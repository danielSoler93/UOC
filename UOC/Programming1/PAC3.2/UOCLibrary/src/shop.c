#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shop.h"

void shopInit(tShop *shop){
	/*
	 * Initialize tShop tuple.
	 * 
	 * input:
	 * 	shop: Shop to initialize
	 * 
	 * output:
	 * 	initialized shop
	 */
	shop->numClients = 0;
}

void clientCopy (tClient client1, tClient *client2){
	 /*
	 * Copy information from one client to another client.
	 * 
	 * input:
	 * 	client1: client to copy
	 * 	
	 * 	client2: client variable use as a destination
	 * 
	 * output:
	 * 		client2: variable client2 with the client1 information stored
	 */
	client2->dni = client1.dni;
	strcpy(client2->name, client1.name);
	strcpy(client2->email,client1.email);
	client2->accumulated = client1.accumulated;
	client2->thereIsCupon = client1.thereIsCupon;
}

void clientInit(tClient *client, int dni, char *name, char *email, float accumulated, bool thereIsCupon){
	 /*
	 * Initalize tClient tuple with dni, person's name, email,
	 * money accumulated an a ThereIsCupon bool. 
	 * 
	 * input:
	 * 	client1: client variable
	 * 	
	 * 	dni: client's dni
	 * 
	 * name: client name
	 * 
	 * email: client email
	 * 
	 * accumulated: total amount of money the client spent in the shop
	 * 
	 * thereIsCupon: bool to to know whether or not it's 
	 * 				 the discountalready exhcange.
	 * 
	 * output:
	 * 		client1: client variable with all the desired infromation stored.
	 */
	char nameClient1[MAXSTRINGLEN];
	strcpy(nameClient1, name);
	char emailClient1[MAXSTRINGLEN];
	strcpy(emailClient1, email);
	client->dni = dni;
	strcpy(client->name, name);
	strcpy(client->email, email);
	client->accumulated = accumulated;
	client->thereIsCupon = thereIsCupon;
}


int posClient(tShop shop, int dni){
	/*
	 * Return the position of the client with the passed id
	 * or -1 if it's not found.
	 * 
	 * input:
	 * 	shop: shop dicounts storage
	 * 	
	 * 	dni: dni to llok for
	 *
	 * output:
	 * 		position: position of the client with id=dni
	 * 	    inside the shop storage.
	 */
	int position = 0;
	int i;
	for(i=0; i < shop.numClients; i++){
		if (shop.clients[i].dni == dni){
			return position;
		position ++;
		}
	}
	return -1;
}

void insertClient(tShop *shop, tClient client){
	/*
	 * Insert client by id order from
	 * high to low numbers by:
	 * 
	 * 1- Check whether or not the id is already inside the database
	 * 2- Check if there's enough space or the database is full
	 * 3- Look for the insertion position of client
	 * 4- Add client moving all other clients to the right of the table.
	 * 5- Retrieve the succes/fail of the action to the user via terminal.
	 * 
	 * 
	 * input:
	 * 	shop: shop discounts storage
	 * 	
	 * 	client: client to insert
	 *
	 * output:
	 * 		shop: discounts storage with the client inserted on the right position.
	 * 
	 */
	int position=0;
	if(posClient(*shop, client.dni) == -1){
		if(shop->numClients == MAXCLIENTS){
			printf("No space left for clients\n");
		} else{
		while(shop->clients[position].dni > client.dni){
			position++;
			}
		}
		tClient clientReplace = client;
		tClient nextClientReplace;
		int i;
		for(i=position; i<=shop->numClients; i++){
			nextClientReplace = shop->clients[i];
			clientCopy(clientReplace, &(shop->clients[i]));
			clientReplace = nextClientReplace;
		}
		shop->numClients ++;
		printf("\nClient introduced in position %d. Current Number of Clients %d\n", position + 1, shop->numClients);
	} else{
		printf("That client already exists in the shop storage\n");
	}
	
}

void addAmountClient(tShop *shop, int dni, int import){
	 /*
	 * Add the value of the shopping to the accumuleted field of a client tuple.
	 * 
	 * input:
	 * 	shop: shop discounts storage
	 * 	dni: client id
	 *  import: shopping import to accumulate
	 * 
	 *
	 * output:
	 * 		shop: discount storage with the already accumulated shopping.
	 * 
	 */
	int position =posClient(*shop, dni);
	if(position != -1){
		shop->clients[position].accumulated += import;
		printf("Import of %d added. Total accumulated %f\n", import, shop->clients[position].accumulated);
	} else if(position == -1){
		printf("Client with dni %d not found. Check the number\n", dni);
	}
}

void generateDiscount(tShop *shop){
	 /*
	 * Generate a voucher if accumuleted>100E
	 * 
	 * input:
	 * 	shop: shop discounts storage
	 *
	 * output:
	 * 		STDOUT: Vouchers information
	 * 
	 */
	int i;
	for(i=0; i < shop->numClients; i++){
		float cuponAmount = 0;
		if(shop->clients[i].accumulated >= MINACCUMULATED){
			tClient client = shop->clients[i];
			cuponAmount = (client.accumulated * 0.03);
			printf("\nClient %d: New Cupon of %f Euros\n", client.dni, cuponAmount);
			shop->clients[i].accumulated = 0;
			shop->clients[i].thereIsCupon = TRUE;
		} 
	}
}