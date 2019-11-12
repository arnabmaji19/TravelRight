//
// Created by Arnab on 06-11-2019.
//

#ifndef TRAVELRIGHT_LOCALTRAVEL_H
#define TRAVELRIGHT_LOCALTRAVEL_H

#endif //TRAVELRIGHT_LOCALTRAVEL_H

void displayLocalTravelOptions(){
    printf("Do you want to opt for Local Travel for transportation or sight seeing?\n");
    printf("Press 'Y' to confirm or 'N' to view another:\n");
    char confirmation;
    fflush(stdin);
    scanf("%c",&confirmation);
    while((confirmation != 'y' && confirmation != 'Y')  && (confirmation != 'n' && confirmation != 'N')){
        printf("Oops! not a valid selection.\n");
        printf("try again!\n");
        fflush(stdin);
        scanf("%c",&confirmation);
    }
    if(confirmation == 'n' || confirmation == 'N'){
        printf("Thank you for your choice!\n");
        SELECTED_LOCAL_TRAVEL_OPTION = 0;
        return;
    }
    printf("Please select your local travel options:\n");
    printf("\t1. For Transportation only(%d Per Head)\n",localTravelPrices[SELECTED_TRIP_TYPE][0]);
    printf("\t2. For Sight Seeing only(%d Per Head)\n",localTravelPrices[SELECTED_TRIP_TYPE][1]);
    printf("\t3. Both(%d Per Head)\n",localTravelPrices[SELECTED_TRIP_TYPE][2]);
    int localTravelOption;
    scanf("%d",&localTravelOption);
    while(localTravelOption < 1 || localTravelOption > 3){
        printf("Oops! not a valid selection.\n");
        printf("try again!\n");
        scanf("%d",&localTravelOption);
    }
    localTravelOption--;
    printf("Press 'Y' to confirm or 'N' to view another:\n");
    fflush(stdin);
    scanf("%c",&confirmation);
    while((confirmation != 'y' && confirmation != 'Y')  && (confirmation != 'n' && confirmation != 'N')){
        printf("Oops! not a valid selection.\n");
        printf("try again!\n");
        fflush(stdin);
        scanf("%c",&confirmation);
    }
    if(confirmation == 'Y' || confirmation == 'y'){
        //Save Local Travel Options
        SELECTED_LOCAL_TRAVEL_OPTION = localTravelOption;
    } else {
        displayLocalTravelOptions();
    }

}