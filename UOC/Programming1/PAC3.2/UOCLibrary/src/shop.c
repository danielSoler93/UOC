#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shop.h"

void shopInit(tShop *shop){
	shop->numClients = 0;
}

void clientCopy (tClient client1, tClient *client2){
	client2->dni = client1.dni;
	strcpy(client2->name, client1.name);
	strcpy(client2->email,client1.email);
	client2->accumulated = client1.accumulated;
	client2->thereIsCupon = client1.thereIsCupon;
}

void clientInit(tClient *client, int dni, char *name, char *email, float accumulated, bool thereIsCupon){
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

void clientAdd(tShop *shop, tClient client){
	shop->clients[shop->numClients] = client;
	shop->numClients ++;
}

int posClient(tShop shop, int dni){
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
		for(i=position; i<(*shop).numClients; i++){
			nextClientReplace = shop->clients[i];
			clientCopy(clientReplace, &(shop->clients[i]));
			clientReplace = nextClientReplace;
			i++;
		}
		shop->clients[shop->numClients] = nextClientReplace;
		shop->numClients ++;
		printf("\nClient introduced in position %d. Current Number of Clients %d\n", position + 1, shop->numClients);
	} else{
		printf("That client already exists in the shop storage\n");
	}
	
}

void addAmountClinet(tShop *shop, int dni, int import){
	int position =posClient(*shop, dni);
	if(position != -1){
		shop->clients[position].accumulated += import;
		printf("Import of %d added. Total accumulated %f", import, shop->clients[position].accumulated);
	} else if(position == -1){
		printf("Client with dni %d not found. Check the number", dni);
	}
}