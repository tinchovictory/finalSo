#include <stdio.h>
#include <stdlib.h>
#include "includes/db.h"

void checkDbError(DbCode code);

int main(void) {
	Db_t db;
	DbCode dbCode;

	/* Create a db connection */
	dbCode = dbInit(&db);
	checkDbError(dbCode);

	/* Install Db */
	dbCode = installDb(db);
	checkDbError(dbCode);

	/*** TESTING ****/

	dbCode = addFlight(db, 2, "Buenos Airesss", "JFK", 100, 50, "26/01/2018");
	checkDbError(dbCode);

	/*** END TESTING *****/

	/* Close connection */
	dbClose(db);


	return 0;

}


 void checkDbError(DbCode code) {
	if(code == DB_OK) {
		return;
	}

	printf("Db fail\n");
	exit(1);
}