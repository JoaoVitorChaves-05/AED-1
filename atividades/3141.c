#include <stdio.h>

int main(int argc, char **argv)
{
    char person_name[55];
    int birth_day, birth_month, birth_year;
    int current_day, current_month, current_year;

    scanf("%[^\n]%*c", person_name);
    scanf("%d/%d/%d", &birth_day, &birth_month, &birth_year);
    scanf("%d/%d/%d", &current_day, &current_month, &current_year);

    int age = birth_year - current_year;

    int days_in_month[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

    int birth_total_days = days_in_month[birth_month - 1] + birth_day;
    int current_total_days = days_in_month[current_month - 1] + current_day;

    if ((age == 0) || (birth_total_days < current_total_days))
        printf("Voce tem %d anos %s.\n", (age - 1) < 0 ? 0 : age - 1, person_name);
    else if (birth_total_days == current_total_days)
        printf("Feliz aniversario!\nVoce tem %d anos %s.\n", age, person_name);
    else
        printf("Voce tem %d anos %s.\n", age, person_name);

    return 0;
}
