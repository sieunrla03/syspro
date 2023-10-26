#include <stdio.h> 

struct student {
   int id; 
   char name[20]; 
   char catagory[20];
   int ex_date;
   int stock;
};

int main(int argc, char* argv[]) 
{ 
    int output;
   scanf("%d", &output);
   struct student rec;
   FILE *fp;
   if (argc != 2) {
      fprintf(stderr, "How to use: %s FileName\n", argv[0]);
      return 1; 
   }
   if(output == 0){
       fp = fopen(argv[1], "r");
       printf("%-9s %-7s %-7s %-4s %-4s \n", "ID", "Name", "catagory", "ex_date", "stock"); 
       while (fscanf("%d %s %s %d %d", &rec.id, &rec.name, &rec.catagory, & rec.ex_date, &rec.stock)==5) 
          printf(fp, "%d %s %s %d %d ", rec.id, rec.name, rec.catagory, rec.ex_date, rec.stock);
       fclose(fp);
   }
   else if(output == 1){
       fp = fopen(argv[2], "r");
       printf("%-9s %-7s %-7s %-4s %-4s \n", "ID", "Name", "catagory", "ex_date", "stock"); 
       while (fscanf("%d %s %s %d %d", &rec.id, &rec.name, &rec.catagory, & rec.ex_date, &rec.stock)==5)
            if(rec.ex_date >= 2023 && rec.stock > 0)
                printf(fp, "%d %s %s %d %d ", rec.id, rec.name, rec.catagory, rec.ex_date >= 2023, rec.stock > 0);
       fclose(fp);
   }
   return 0;
} 
