//Constants
#define MAXPURCHASES 50
#define MAXCLIENTS 50
#define MAXSTRINGLEN 100

typedef enum {FALSE, TRUE} bool;

typedef struct{
	int dni;
	char name [MAXSTRINGLEN];
	char email [MAXSTRINGLEN];
	float accumulated;
	bool thereIsCupon;
} tClient;

typedef struct{
	tClient clients [MAXCLIENTS];
	int numClients;
} tShop;


void shopInit(tShop *shop);

void clientCopy (tClient client1, tClient *client2);

void clientInit(tClient *client, int dni, char *name, char *email, float accumulated, bool thereIsCupon);

int posClient(tShop shop, int dni);

void clientAdd(tShop *shop, tClient client);

void insertClient(tShop *shop, tClient client);