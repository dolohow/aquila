/**
 * @file Synthesizer.h
 *
 * Base class for SFML-based audio synthesizers.
 *
 * This file is part of the Aquila DSP library.
 * Aquila is free software, licensed under the MIT/X11 License. A copy of
 * the license is provided with the library in the LICENSE file.
 *
 * @package Aquila
 * @version 3.0.0-dev
 * @author Zbigniew Siciarz
 * @date 2007-2013
 * @license http://www.opensource.org/licenses/mit-license.php MIT
 * @since 3.0.0
 */

#ifndef SYNTHESIZER_H
#define SYNTHESIZER_H

#include "../global.h"
#include "../wrappers/SoundBufferAdapter.h"
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <string>

namespace Aquila
{
    typedef std::map<std::string, FrequencyType> NoteMapType;

    NoteMapType initNoteMap();

    class AQUILA_EXPORT Synthesizer
    {
    public:
        /**
         * Creates the synthesizer object.
         *
         * @param sampleFrequency sample frequency of the audio signal
         */
        Synthesizer(FrequencyType sampleFrequency):
            m_sampleFrequency(sampleFrequency)
        {
        }

        void playNote(std::string note, unsigned int duration = 500);

        virtual void playFrequency(FrequencyType frequency, unsigned int duration) = 0;

    protected:
        /**
         * Sample frequency of the generated signal.
         */
        const FrequencyType m_sampleFrequency;

        /**
         * Audio buffer for playback.
         */
        SoundBufferAdapter m_buffer;

        /**
         * A mapping from note names to frequencies.
         */
        static NoteMapType m_notes;
    };
}

#endif // SYNTHESIZER_H