// book struct
#include <stdio.h>
struct book
{
    int bookid;
    char title[30];
    char author[20];
    float price;
};
void print_book(struct book b1)
{
    printf("Name of the book : %s.\n",b1.title);
    printf("Name of the author : %s.\n",b1.author);
    printf("Book id : %d\n",b1.bookid);
    printf("Price of the book : %d ",b1.price);
}

int main()
{
    struct book b1;
    printf("Enter the name of the book : ");
    scanf("%s",&b1.title);
    printf("Enter the name of the author : ");
    scanf("%s",&b1.author);
    printf("Enter the  book id : ");
    scanf("%d",&b1.bookid);
    printf("Enter the price of the book : ");
    scanf("%f",&b1.price);
    print_book(b1);
}