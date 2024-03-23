#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14
void flush(){     // Function for character error
        int c;
        do {
            c = getchar();
        } while (c != '\n' && c != EOF);
    }
enum Shapes{Triangle=1,Quadrilateral=2,Circle=3,Pyramid=4,Cylinder=5};
enum Calculators{Area=1,Perimeter=2,Volume=3};
int select_shape ()
{
 enum Shapes x;
 int m;
 printf("Select a shape to calculate:\n");         // Menu created to select calculator
 printf("-------------------------------\n");
 printf("1. Triangle\n");
 printf("2. Quadrilateral\n");
 printf("3. Circle\n");
 printf("4. Pyramid\n");
 printf("5. Cylinder\n");
 printf("0. Exit\n");
 printf("-------------------------------\n");
 printf("Input :");
 do
 {
 scanf("%u",&x);
 flush();
 printf("\n");
 if(x == 0)
    exit(0);
 else if(x != Triangle && x != Quadrilateral && x != Circle && x != Pyramid && x != Cylinder)
    printf("Warning!! Enter a valid number\n\n");
 }while(x != Triangle && x != Quadrilateral && x != Circle && x != Pyramid && x != Cylinder);
return x;
}
int select_calc ()
{
 enum Calculators y;
 printf("Select calculator:\n");                                 // Menu created to select calculator
 printf("-------------------------------\n");
 printf("1. Area\n");
 printf("2. Perimeter\n");
 printf("3. Volume\n");
 printf("0. Exit\n");
 printf("-------------------------------\n");
 printf("Input :");
 do
 {
 scanf("%u",&y);
 flush();
 printf("\n");
  if(y == 0)
    exit(0);
 else if(y != Area && y != Perimeter && y != Volume)
    printf("Warning!! Enter a valid number\n\n");
}while(y != Area && y != Perimeter && y != Volume);
return y;

}
int calculate (int (*s_shape)(), int (*s_calculator)())
{
    enum Shapes p = s_shape(select_shape);       // Shape function taken as parameter
    float a,b,c,d,s,r,area,perimeter,volume,base_surface,lateral_surface,surface_area;
    switch(p)
    {
    case Triangle:               // Arithmetic operations performed for triangle shape
        printf("\n");
        int calc_triangle(int);
      {
           enum Calculators k = s_calculator(select_calc);  // Calculation function taken as parameter
             switch(k)
             {
             case Area:
             printf("Please enter three sides of Triangle :\n");
             do
             {
             scanf("%f",&a);
             flush();
             scanf("%f",&b);
             flush();
             scanf("%f",&c);
              flush();
              s = (a+b+c)/2;
              printf("\n");
              if(a <= 0 || b <= 0 || c <= 0 )
                printf("ERROR ! Please enter a valid entry\n\n");
              else if(a+b <= c || a+c <= b || b+c <= c)
                printf("ERROR ! Please enter a valid triangle\n");
              else if(a > 0 && b > 0 && c > 0 && a+b >= c && a+c >= b && c+b >= a)
                {
                 area = sqrt(s*(s-a)*(s-b)*(s-c));  // area calculated via 𝑯𝒆𝒓𝒐𝒏′𝒔 𝑭𝒐𝒓𝒎𝒖𝒍𝒂= √𝒔∗(𝒔−𝒂)∗(𝒔−𝒃)∗(𝒔−𝒄)
                 printf("Area of TRIANGLE is : %.2f\n",area);
             }
             }while(a+b <= c || b+c <= a || a+c <= b || a <= 0 || b <= 0 || c <= 0 );
              break;

            case Perimeter:
             printf("Please enter three sides of Triangle :\n");
             do
             {
              scanf("%f",&a);
             flush();
             scanf("%f",&b);
             flush();
             scanf("%f",&c);
              flush();
             s = (a+b+c)/2;
             printf("\n");
              if(a <= 0 || b <= 0 || c <= 0 )
                printf("ERROR ! Please enter a valid entry\n\n");
              else if( a+b <= c || a+c <= b || b+c <= c)
                printf("ERROR ! Please enter a valid triangle\n\n");
             else if(a > 0 && b > 0 && c > 0 && a+b >= c && a+c >= b && c+b >0)
                {
                 perimeter = a+b+c;  // perimeter calculated
                 printf("Perimeter of TRIANGLE is : %.2f\n",perimeter);
             }
             }while(a+b <= c || b+c <= a || a+c <= b || a <= 0 || b <= 0 || c <= 0);

                break;
             case Volume:
                       printf("ERROR ! You can not calculate the volume of a triangle.Please try again.\n\n");
                        calculate(select_shape,select_calc);
                break;
             }
             return 0;
      }
        break;                     // End of triangle shape

    case Quadrilateral:            //  Arithmetic operations performed for quadrilateral shape
         printf("\n");
         int calc_quadrilateral(int);
         {
         enum Calculators k = s_calculator(select_calc);     // Calculation function taken as parameter
         switch(k)
         {
             case Area:
             printf("Please enter four sides of QUADRILATERAL :\n");
             do
             {
             scanf("%f",&a);
             flush();
             scanf("%f",&b);
             flush();
             scanf("%f",&c);
             flush();
             scanf("%f",&d);
             s = (a+b+c+d)/2;
             printf("\n");
             if(a <= 0 || b <= 0 || c <= 0 || d <= 0)
                printf("ERROR ! Please enter a valid entry\n\n");
             else if(a > 0 && b > 0 && c > 0 && d > 0)
                {
                 area = sqrt((s-d)*(s-a)*(s-b)*(s-c));   // area calculated via 𝑩𝒓𝒂𝒉𝒎𝒂𝒈𝒖𝒑𝒕𝒂′𝒔 𝑭𝒐𝒓𝒎𝒖𝒍𝒂= √(𝒔−𝒂)∗(𝒔−𝒃)∗(𝒔−𝒄)∗(𝒔−𝒅)
                 printf("Area of QUADRILATERAL is : %.2f\n",area);
             }
             }while(a <= 0 || b <= 0 || c <= 0 || d <= 0);

              break;
             case Perimeter:
             printf("Please enter four sides of quadrilateral :\n");
             do
             {
             scanf("%f",&a);
             flush();
             scanf("%f",&b);
             flush();
             scanf("%f",&c);
             flush();
             scanf("%f",&d);
             s = (a+b+c+d)/2;
             printf("\n");
             if(a <= 0 || b <= 0 || c <= 0 || d <= 0)
                printf("ERROR ! Please enter a valid entry\n\n");
             else if(a > 0 && b > 0 && c > 0 && d > 0)
                {
                 perimeter = a+b+c+d;  // perimeter calculated
                 printf("Perimeter of QUADRILATERAL is : %.2f\n",perimeter);
             }
             }while(a <= 0 || b <= 0 || c <= 0 || d <= 0);
                break;
             case Volume:
                        printf("ERROR ! You can not calculate the volume of a quadrilateral.Please try again.\n\n");
                        calculate(select_shape,select_calc);
                break;
         }
         return 0;
         }
        break;     // End of quadrilateral shape
        case Circle:                                      //  Arithmetic operations performed for circle shape
             printf("\n");
             int calc_circle(int);
             {
               enum Calculators k = s_calculator(select_calc); // Calculation function taken as parameter
               switch(k)
             {
                 case Area:
                        printf("Please enter the radius of the circle :\n");
                        do
                        {
                        scanf("%f",&r);
                        flush();
                        printf("\n");
                        if(r <= 0)
                            printf("ERROR ! Please enter a valid entry\n\n");
                        else if(r > 0)
                    {
                        area = PI * r * r;  // area calculated
                        printf("Area of CIRCLE : %.2f\n",area);
                    }

                    }while(r <= 0);
                     break;
                 case Perimeter:
                        printf("Please enter the radius of the circle :\n");
                        do
                        {
                        scanf("%f",&r);
                        flush();
                        printf("\n");
                        if(r <= 0)
                            printf("ERROR ! Please enter a valid entry\n\n");
                        else if(r > 0)
                       {
                        perimeter = PI * r * 2; // perimeter calculated
                        printf("Perimeter of CIRCLE : %.2f",perimeter);
                       }
                    }while(r <= 0);

                 break;
                 case Volume:
                    printf("ERROR ! You can not calculate the volume of a Circle.Please try again.\n\n");
                    calculate(select_shape,select_calc);
                    break;
             }
             return 0;
                         }  // End of circle shape
        break;
    case Pyramid:      //  Arithmetic operations performed for pyramid shape
          printf("\n");
          int calc_pyramid(int);
          {
              enum Calculators k = s_calculator(select_calc);  // Calculation function taken as parameter
              switch(k)
              {
             case Area:
                    printf("Please enter the base side and slant height of a Pyramid :\n");
                    do
                    {
                        scanf("%f",&a);
                        flush();
                        scanf("%f",&b);
                        flush();
                       printf("\n");
                    if(a <= 0 || b <= 0)
                        printf("ERROR ! Please enter a valid entry.\n");
                    else if(a > 0 && b > 0)
                    {
                     base_surface = a * a;
                     lateral_surface = 2 * a * b;    // surface areas calculated
                     surface_area = base_surface + lateral_surface;
                     printf("Base surface Area of a PYRAMID : %.2f\n\n",base_surface);
                     printf("Lateral surface Area of a PYRAMID : %.2f\n\n",lateral_surface);
                     printf("Surface Area of a PYRAMID : %.2f\n\n",surface_area);
                    }
                   }while(a <= 0 || b <= 0);

                break;
             case Perimeter:
                   printf("Please enter the base side and slant height of a Pyramid :\n");
                    do
                    {
                    scanf("%f",&a);
                    flush();
                    scanf("%f",&b);
                    flush();
                    printf("\n");
                    if(a <= 0 || b <= 0)
                        printf("ERROR ! Please enter a valid entry.\n");
                    else if(a > 0 && b > 0)
                    {
                     perimeter = 4 * a;  // base perimeter calculated
                     printf("Base surface Perimeter of a PYRAMID : %.2f\n",perimeter);
                    }

                 }while(a <= 0 || b <= 0);
                 break;
             case Volume:
                  printf("Please enter the base side and height of a Pyramid :\n");
                  do
                  {
                    scanf("%f",&a);
                    flush();
                    scanf("%f",&b);
                    flush();
                  printf("\n");
                  if(a <= 0 || b <= 0)
                        printf("ERROR ! Please enter a valid entry.\n");
                  else if(a > 0 && b > 0)
                  {
                     volume =  (a * a * b)/3;   // volume calculated
                     printf("Volume of a PYRAMID : %.2f\n",volume);
                  }
                 }while(a <=0 || b <= 0);
                break;
              }           // End of pyramid shape
              return 0;
                        }
        break;
    case Cylinder:            //  Arithmetic operations performed for cylinder  shape
         printf("\n");
         int calc_cylinder(int);
         {
           enum Calculators k = s_calculator(select_calc);  // Calculation function taken as parameter
            switch(k)
            {
              case Area:
                 printf("Please enter the radius and height of a Cylinder :\n");
                 do
                 {
                 scanf("%f",&r);
                 flush();
                 scanf("%f",&a);
                 flush();
                 printf("\n");
                 if(a <= 0 || r <= 0)
                    printf("ERROR ! Please enter valid entry.\n\n");
                 else if(a > 0 && r > 0)
                 {
                     base_surface = PI * r * r;
                     lateral_surface = 2 * PI * r * a;   // areas calculated
                     surface_area = 2 * PI * r * (r+a);
                     printf("Base surface Area of a CYLINDER : %.2f\n\n",base_surface);
                     printf("Lateral surface Area of a CYLINDER : %.2f\n\n",lateral_surface);
                     printf("Surface Area of a CYLINDER : %.2f\n\n",surface_area);
                 }
                 }while(a <= 0 || r <= 0);
                  break;
              case Perimeter:
                 printf("Please enter the radius and height of a Cylinder :\n");
                 do
                 {
                 scanf("%f",&r);
                 flush();
                 scanf("%f",&a);
                 flush();
                 printf("\n");
                 if(a <= 0 || r <= 0)
                    printf("ERROR ! Please enter valid entry.\n");
                 else if(a > 0 && r > 0)
                 {
                  perimeter =  2 * PI * r;  // base perimeter calculated
                  printf("Base surface Perimeter of a CYLINDER : %.2f\n",perimeter);
                 }
                    }while(a <= 0 || r <= 0);

                 break;
              case Volume:
                    printf("Please enter the radius and height of a Cylinder :\n");
                 do
                 {
                 scanf("%f",&r);
                 flush();
                 scanf("%f",&a);
                 flush();
                 printf("\n");
                 if(a <= 0 || r <= 0)
                    printf("ERROR ! Please enter valid entry.\n");
                 else if(a > 0 && r > 0)
                 {
                  volume =  PI * r * r * a;  // volume calculated
                  printf("Volume of a CYLINDER : %.2f\n",volume);
                 }
                 }while(a <= 0 || r <= 0);
            break;
            default:
                printf("Please enter a valid entry\n\n");
            }
             return 0;  // End of cylinder shape
         }
        break;
    }
}
int main()
{
    printf("Welcome to the geometric calculator!\n\n");
    calculate(select_shape,select_calc);     // Calling calculate_function
    return 0;
}


