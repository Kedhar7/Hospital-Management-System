#include<stdio.h>
#include<string.h>
#include<conio.h>
#include <stdlib.h>

void mainmenu();
void welcomescreen();
void title();
void loginscreen();
void addpatientrec(); 
void viewpatients();

struct patients
{
char first_name[50];
    char last_name[50];
    char age[25];
	char disease[50];
	char doctor[50];
};
int choose=5;
int select=4;                                                                              
 void addpatientrec()
{
	FILE *fp;
	struct patients info;
	printf("\n\n\n\n\t\t\t -------------Add patients rec-----------------");
	fp=fopen("patients_rec.text","a");
	printf("\n\n\n Enter first name:");
	scanf("%s",info.first_name);
	 	  fprintf(fp,"%s",info.first_name);
	 	  fprintf(fp,"%s","\t\t");
	printf("enter last name :");
	scanf("%s",info.last_name);
		  fprintf(fp,"%s",info.last_name );
		  	 	  fprintf(fp,"%s"," \t\t");
	printf("enter age :");
	scanf("%s",info.age);
		  fprintf(fp,"%s",info.age);
		  	 	  fprintf(fp,"%s","\t\t");
	printf("enter the disease :");
	scanf("%s",info.disease);
		fprintf(fp,"%s",info.disease);                                   
			fprintf(fp,"%s"," \t\t");
	printf("enter the doctor :");
	scanf("%s",info.doctor);
		fprintf(fp,"%s",info.doctor);
			 	  fprintf(fp,"%s","\n\n");
	        
      if (fp==NULL)
      {
      	printf("cannot open file");	
      	}
		else
          fclose(fp);
          printf("stored succesfully ..press to go to main menu");
          getch();
        mainmenu();
          //fp=fopen("patients_rec.text","w");
          //fclose(fp);
          fflush(fp);
	  }
void welcomescreen()
{
	printf("\n\n\t\t\t######################################");
    printf("\n\t\t\t\t WELCOME TO \t\t\t\t\t#\n");
    printf("\n\t\t\t#HOSPITAL MANGEMENT SYSTEM #\n");
    printf("\n\n\t\t\t######################################");
    printf("\n\nPRESS ANY KEY TO CONTINUE......\n");
    getch();
    system("cls");
}

void title()
{
    printf("\n\n\t\t*********************************");
    printf("\n\t\t\t\t\t\t\t     SM HOSPITAL ");
    printf("\n\t\t*******************************");
 }
 
 void choicelist()
 {
 	      printf("\n 1. add patients record");                            
          printf("\n 2. view patients");
          printf("\n 3. emergancy situation");
          printf("\n 4. exit");
  }

void mainmenu ()
{
    system("cls");
	welcomescreen();
	title();
	choicelist();  
    printf("\n \n choose from 1-4 : ");

    scanf("%i",&choose);
    switch(choose)
    {
        case 1:
        addpatientrec();
        break;
        
        case 2:                                                                             
        system("cls");
        viewpatients();
        break;
        
        case 3:
        printf("emergancy situation");
        break;      
        case 4:
        printf("THANK YOU FOR VISITING!!!");
        break;         
        default:
        printf("invalid option");
        getch();
    }   
    if (choose==3)
    { printf(" select 1-4 \n\n");
      printf("1.accidents \n");
      printf("2.burns \n");
      printf("3.diarrhea and dehydration \n");
      printf("4.cardiac arrest \n");
      scanf("%i",&select);
      switch(select)                                                                      
      {
        case 1:
        printf("\n accidents \n");
        printf("\ncall the surgeons according to type of injury and prepare the OT\n");
        break;
        case 2:
        printf("\n burns \n");
        printf("\nassign the case to duty doctor unless the case is very serious\n");
        break;
        case 3:
        printf("\ndiarrhea and dehydration \n");
        printf("\nstart the patient on iv fluids and monitor the vitals\n");
        break;
        case 4:
        printf("\ncardiac arrest \n");
        printf("\nits a code red situation\n");
        
        break;
        
        default:                                                                         
        printf("\ninvalid option\n");
        getch();
        system("cls");    
             }    
     }
         
     }                
     void loginscreen()
     {
        char username[50];
         char password[50];
         char originalusername[25]="sm hospital";
         char orignalpassword[25]="sm@0405";
             printf("\n\n\n\n\t\t\tEnter the username and password :");
             printf("\n\n\n\t\t\t\tUSERNAME : ");
             gets(username);
             printf("\n\n\n\t\t\t\tPASSWORD : ");
             gets(password);
            // printf("\n\n\n\nSUCCESSFULLY LOGGED IN......\n");
            // printf("\n\n\n\nPRESS ANY KEY TO   CONTINUE.....");                                                                  
            //getch();
            // mainmenu();
            if (strcmp(username,originalusername)==0 && strcmp(password,orignalpassword)==0)
             {
                 printf("\n\n\n\n........login successful.........");
                 getch();
                 mainmenu();
             }
             else
             {
                 printf("\n\n\n\n INCORRECT PASSWORD"); 
                 getch();
                 system("cls");
             }
           }
   void viewpatients()
{
		FILE*fptr;
		fptr=fopen("patients_rec.text","r");
		 printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!list of  patients!!!!!!!!!!!!!!!!!!!!!!!!!!! \n\n");                                    
		 printf("\nFirst Name\tLast Name\tAge\t\tDisease\t\t\tDoctor\n\n"); 
		 printf("-----------------------------------------------------------------------------\n\n");		 
		 char c;
		c = fgetc(fptr);
        while (c != EOF)
        {
          printf ("%c", c);
          c = fgetc(fptr);
       }
  
     fclose(fptr);
              printf("\n....presss to go to main menu\n");
          getch();
        mainmenu();		
	}  

	int main()
	{
		loginscreen();		
		return 0; 
	}

