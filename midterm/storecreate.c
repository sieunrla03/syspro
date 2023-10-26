#include <stdio.h> 

struct student {
   int id; 
   char name[20]; 
   char catagory[20];
   int ex_data;
   int stock;
};

int main(int argc, char* argv[]) 
{ 
   struct student rec;
   FILE *fp;
   if (argc != 2) {
      fprintf(stderr, "How to use: %s FileName\n", argv[0]);
      return 1; 
   }
   fp = fopen(argv[1], "w");
   printf("%-9s %-7s %-5s %-3s %-1s \n", "ID", "Name", "catagory", "ex_data", "stock"); 
   while (scanf("%d %s %s %d %d", &rec.id, &rec.name, &rec.catagory, & rec.ex_data, &rec.stock)==5) 
      fprintf(fp, "%d %s %s %d %d ", rec.id, rec.name, rec.catagory, rec.ex_data, rec.stock);
   fclose(fp);
   return 0;
} 
