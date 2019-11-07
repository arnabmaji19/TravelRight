//
// Created by Arnab on 06-11-2019.
//

#ifndef TRAVELRIGHT_DATESELECTION_H
#define TRAVELRIGHT_DATESELECTION_H

#endif //TRAVELRIGHT_DATESELECTION_H

const int monthDays[12] = {31, 28, 31, 30, 31, 30,
                           31, 31, 30, 31, 30, 31};


int countLeapYears(Date d)
{
    int years = d.year;

    if (d.month <= 2)
        years--;

    return years / 4 - years / 100 + years / 400;
}
int getDifference(Date dt1, Date dt2)
{
    long int n1 = dt1.year*365 + dt1.day;

    for (int i=0; i<dt1.month - 1; i++)
        n1 += monthDays[i];

    n1 += countLeapYears(dt1);

    long int n2 = dt2.year*365 + dt2.day;
    for (int i=0; i<dt2.month - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(dt2);

    return (n2 - n1);
}

void selectDate(){
    printf("Please enter date of journey:(dd:mm:yyyy):\n");
    scanf("%d%*c%d%*c%d",&DATE_OF_JOURNEY.day,&DATE_OF_JOURNEY.month,&DATE_OF_JOURNEY.year);
    printf("Please enter date of return:(dd:mm:yyyy):\n");
    scanf("%d%*c%d%*c%d",&DATE_OF_RETURN.day,&DATE_OF_RETURN.month,&DATE_OF_RETURN.year);
    printf("Please verify your dates:\n");
    printf("\tDate of Journey:%02d:%02d:%d\n",DATE_OF_JOURNEY.day,DATE_OF_JOURNEY.month,DATE_OF_JOURNEY.year);
    printf("\tDate of Return:%02d:%02d:%d\n",DATE_OF_RETURN.day,DATE_OF_RETURN.month,DATE_OF_RETURN.year);
    printf("Enter 0 to confirm or 1 to enter again:\n");
    int confirmation;
    scanf("%d",&confirmation);
    while(confirmation < 0 || confirmation > 1){
        printf("not a valid selection.");
        printf("please try again!");
        scanf("%d",&confirmation);
    }

    if(confirmation == 0){
        //Save dates
        int days = getDifference(DATE_OF_JOURNEY,DATE_OF_RETURN);
        if(days <= 0){
            printf("Invalid Dates!\n");
            printf("Try again!\n");
            selectDate();
            return;
        }
        int month = DATE_OF_JOURNEY.month;
        if((month >= 8 && month <= 12) || (month >= 1 && month <= 3)){
            //Season Prices are High.
            SEASON_STATUS = 1;
        }
        TRIP_LENGTH = days;
    } else{
        selectDate();
    }
}

