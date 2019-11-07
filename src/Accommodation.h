//
// Created by Arnab on 06-11-2019.
//

#ifndef TRAVELRIGHT_ACCOMMODATION_H
#define TRAVELRIGHT_ACCOMMODATION_H

#endif //TRAVELRIGHT_ACCOMMODATION_H


void selectAccommodationPackage(){
    printf("Please select your accommodation type:\n");
    printf("\t1. Three Star Hotel\n");
    printf("\t2. Five Star Hotel\n");
    printf("\t3. Seven Star Hotel\n");
    int accommodationSelection;
    scanf("%d",&accommodationSelection);
    accommodationSelection--;
    printf("Please select your Package Type:\n");
    printf("1. European Package\n"
           "2. Canadian Package\n"
           "3. American Package\n"
           "4. Modified American Package\n");
    int packageType;
    scanf("%d",&packageType);
    while(packageType < 1 || packageType > 4){
        printf("Invalid selection.\n Please try again.\n");
        scanf("%d",&packageType);
    }
    packageType--;
    printf("Please verify your selection:\n");
    printf("Accommodation Fee: %d(Per Head, Per Day)\n"
           "Package Fee: %d(Per Head, Per Day)\n",(hotelPrice[SELECTED_TRIP_TYPE].prices[accommodationSelection] +
           (SEASON_STATUS * (EXTRA_CHARGE_FOR_SEASON[SELECTED_TRIP_TYPE]))), packagePrice[SELECTED_TRIP_TYPE].prices[packageType-1]);
    printf("Enter 0 to confirm or 1 to try again:\n");
    int confirmation;
    scanf("%d",&confirmation);
    if(confirmation == 0){
        //Save user's selection.
        SELECTED_ACCOMMODATION_TYPE = accommodationSelection;
        SELECTED_PACKAGE_TYPE = packageType;
        printf("Your selection has been saved!\n");
    } else {
        selectAccommodationPackage();
    }

}
