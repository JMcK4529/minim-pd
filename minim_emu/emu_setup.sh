#!/bin/bash
cmake -DRTAUDIO_API_CORE=ON -DRTAUDIO_API_PULSE=OFF -DRTAUDIO_API_JACK=OFF -DRTAUDIO_BUILD_TESTING=OFF -DRTMIDI_API_JACK=OFF -DRTMIDI_BUILD_TESTING=OFF -DRTMIDI_TARGETNAME_UNINSTALL="uninstall_rtmidi" -S . -B build