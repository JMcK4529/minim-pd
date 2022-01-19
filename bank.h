#pragma once
#include <string>
#include "m_pd.h"

// void cpppost();
// std::string complexcpp(std::string s);

typedef struct _motif{
    int state;
    int n_state;
    float len_syncs;
    float len_spl;
    float pos_spl;
    float pos_syncs;
    float pos_ratio;   
    float last_sync; 
    float* buf;
} t_motif;

enum _motif_state{
    m_clear = -1,
    m_stop  = 0,
    m_base  = 1,
    m_play  = 2,
    m_dub   = 3,
};

extern "C"{
   
    static t_class *bank_class;
    typedef struct _bank{
        int         id;
        t_object    x_obj;
        t_float     f;
        t_inlet*    i_tick_stats;
        t_outlet*   o_loop_sig;
        t_outlet*   o_state_pending;
        t_outlet*   o_list_tick_sync; 
        // t_outlet*   o_active_motif_slot;
        // t_outlet*   o_active_motif_state;
        int         is_active;
        t_float     tick_duration;
        t_float     tick_start;
        t_float     tick_next;
        t_float     tick_current;
        int         tick_action_pending;
        t_float     tick_action_when;
        int         tick_action_nstate;
        t_motif**   motifs_array;
        t_motif*    active_motif_ptr;
        int         active_motif_idx;
        float       last_sync;
    } t_bank;

    void bank_q(t_bank* x);
    void bank_onActivate(t_bank* x);
    void bank_onDeactivate(t_bank* x);
    void bank_onTickLen(t_bank* x, t_floatarg t);
    void bank_onGetPos(t_bank* x);
    void bank_onNextSlot(t_bank* x);
    void bank_onPrevSlot(t_bank* x);
    void bank_onLaunch(t_bank* x);
    void bank_onStop(t_bank* x);
    void bank_onTransportReset(t_bank* x);
    void bank_onReset(t_bank* x);
    void bank_clear_motif(t_motif* m);
    void* bank_new(t_floatarg f);
    void bank_free(t_bank* x);
    void bank_setup(void);
    void bank_dsp(t_bank *x, t_signal **sp);
    t_int* bank_perform(t_int *w);
}