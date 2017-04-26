//Constants
#define MAXDISCOUNTS 50

//Structure definition
typedef enum {FALSE, TRUE} bool;

typedefstruct {
	int	dni;
	float discount;
	bool changed;
} tDiscount;

typedefstruct {
	tDiscount discounts[MAXDISCOUNTS];
	int	numDiscounts;
} tDiscountsShop;

//Function headers
tDiscountsShop sortDiscountsShop(tDiscountsShop table)