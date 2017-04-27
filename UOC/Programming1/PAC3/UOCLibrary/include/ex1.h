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
void initDiscounts(tDiscountsShop *tabDisc);

void sortDiscountsShop(tDiscountsShop *tabDisc);

void discountChanged(tDiscountsShop *tabDisc, int id);

