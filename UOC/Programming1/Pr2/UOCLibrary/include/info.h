#include "data.h"

tError si_getSectionInfo(tBookTable tabB, tSectionTable tabS, char sectionId, tSectionInfo *si );

tBook si_getBook(tBookTable tabB, tSectionInfo si, unsigned int nSub, unsigned int nBook);

void si_listSectionInfo(tBookTable tabB, tSectionInfo si );
