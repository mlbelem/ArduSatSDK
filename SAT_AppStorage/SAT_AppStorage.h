/** @brief  Library to write Arduino application data from Arduino to the supervisor.

    This is the library to use for writing experiment data that you would 
    like downloaded through the ground station network and available to 
    download from the control center.
	
	This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
	
    @author Jorge Ortiz and NanoSatisfi, Inc.
    @date May 2013
*/

#ifndef DSTORE_H
#define DSTORE_H

#include <inttypes.h>
#include <stdlib.h>

#include <nanosat_message.h>
#include <OnboardCommLayer.h>
#include <SAT_ExperimentData.h>


class SAT_AppStorage
{
    private:
        uint8_t _local_address;         //local address of this node
        OnboardCommLayer* commLayer;
    public:
		/**Constructor that has a single ID parameter.
			@param id - The id of the user's arduino on the ArduSat. This allows 
			the supervisor to know which arduino node to send the data back to. 
			The id is assigned by NanoSatisfi.
        */
        SAT_AppStorage(uint8_t id);
		/**The first way to store data. 
			@param edata - A pointer to experiment data. See: SAT_ExperimentData.h
        */
        void store_exp_data(SAT_ExperimentData* edata);
		/**A alternate way to store data using a buffer. 
			@param buf - A pointer to a data buffer.
			@param len - The length in bytes of the buffer.
        */
        void store_exp_data(const uint8_t* buf, size_t len);
};

#endif
