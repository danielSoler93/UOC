//Constants
#define MAXDISCOUNTS 50

//Structure definition
typedef enum {FALSE, TRUE} bool;

typedef struct{
	int	dni;
	float discount;
	bool changed;
} tDiscount;

typedef struct {
	tDiscount discounts[MAXDISCOUNTS];
	int	numDiscounts;
} tDiscountsShop;

//Function headers
void sortDiscountsShop(tDiscount *table);

void discountChanged(tDiscount *table, int id);