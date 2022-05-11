/*
 * ArrayPassenger.h
 *
 *  Created on: 10 may. 2022
 *      Author: Leandro
 */

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	int passengerType;
	int statusFlight;
	int isEmpty;
}ePassenger;

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#endif /* ARRAYPASSENGER_H_ */

/// @brief This function receives the var where the ids counter was saved and adds +1.
/// @param counter pointer to var where the idCounter is located.
/// @return returns the generated Id, or -1 if error(NULL).
int idGenerator(int * counter);

/// @brief this function put the flag isEmpty to TRUE in avery Array position.
/// @param list Pointer to array of passenger.
/// @param len Array length.
/// @return	(-1) if error, (0) if ok.
int initPassengers(ePassenger* list, int len);

/// @brief Searches for the first empty position in the list, and then if it has
/// an available space the values received as parameters will be added.
/// @param list passenger*
/// @param len int
/// @param id int
/// @param name[] char
/// @param lastName[] char
/// @param price float
/// @param passengerType int
/// @param flycode[] char
/// @return int return (-1) if Error or without free space - (0) if ok.
int addPassenger(ePassenger* list, int len, int id, char name[],
char lastName[], float price, int passengerType, char flycode[]);

/// @brief Find a passenger by Id and returns the indez position in array.
/// @param list Passenger*
/// @param len int
/// @param id int
/// @return Return passenger index position or (-1) if invalid length or NULL or passenger not found.
int findPassengerById(ePassenger*list,int len,int id);

/// @brief Remove a passenger by Id (change isEmpty flag to 1).
/// @param list Passenger*
/// @param len int
/// @param id int
/// @return Returns (-1) if Error(incorrect lenght/NULL/or cant find passenger) - (0) if OK.
int removePassenger(ePassenger*list,int len, int id);


int printPassengers(ePassenger*list, int len);



