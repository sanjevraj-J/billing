#include <stdio.h>
#include <string.h>

int cid = 0;
int pid = 0;
int bid = 0;

struct Product {
    char proName[50];
    char proQuantity[10];
    int proId;
    float proCost;
} pro[100];

struct Customer {
    char cusName[50];
    char cusPhno[10];
    int cusId;
} cus[100];

struct Billing {
    int cuID;
    int n;
    struct Items {
        int itmId;
        int itmqua;
    } itm[100];
} bill[100];

void createCustomer() {
    printf("Enter Your Name: ");
    scanf("%s", cus[cid].cusName);
    printf("Enter Your Number: ");
    scanf("%s", cus[cid].cusPhno);
    cus[cid].cusId = cid + 1;
    printf("=====> Data Entered Successfully <====\n");
    cid++;
}

void displayCustomers() {
    for (int i = 0; i < cid; i++) {
        printf("\nCustomer ID: %d\n", cus[i].cusId);
        printf("Customer Name: %s\n", cus[i].cusName);
        printf("Customer Phone Number: %s\n", cus[i].cusPhno);
    }
}

void identifyCustomerByID() {
    int id;
    printf("Enter Customer ID to Search: ");
    scanf("%d", &id);
    int found = 0;
    for (int i = 0; i < cid; i++) {
        if (cus[i].cusId == id) {
            printf("\nCustomer Found!\n");
            printf("Customer ID: %d\n", cus[i].cusId);
            printf("Customer Name: %s\n", cus[i].cusName);
            printf("Customer Phone Number: %s\n", cus[i].cusPhno);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Customer ID not found.\n");
    }
}

void enterProduct() {
    printf("Enter Product Name: ");
    scanf("%s", pro[pid].proName);
    printf("Enter Product Quantity: ");
    scanf("%s", pro[pid].proQuantity);
    printf("Enter Product Cost: ");
    scanf("%f", &pro[pid].proCost);
    pro[pid].proId = pid + 1;
    printf("=====> Product Entered Successfully <====\n");
    pid++;
}

void displayProducts() {
    for (int i = 0; i < pid; i++) {
        printf("\nProduct ID: %d\n", pro[i].proId);
        printf("Product Name: %s\n", pro[i].proName);
        printf("Product Quantity: %s\n", pro[i].proQuantity);
        printf("Product Cost: %.2f\n", pro[i].proCost);
    }
}

void createBill() {
    printf("Enter Your Customer ID: ");
    scanf("%d", &bill[bid].cuID);
    printf("Enter Number of Products You Want to Buy: ");
    scanf("%d", &bill[bid].n);

    for (int i = 0; i < bill[bid].n; i++) {
        printf("Enter the Product ID: ");
        scanf("%d", &bill[bid].itm[i].itmId);
        printf("Enter the Quantity: ");
        scanf("%d", &bill[bid].itm[i].itmqua);
    }

    float total = 0;
    printf("\n====== Bill Summary ======\n");
    for (int i = 0; i < bill[bid].n; i++) {
        int id = bill[bid].itm[i].itmId;
        int qty = bill[bid].itm[i].itmqua;
        float cost = pro[id - 1].proCost;
        printf("%s x %d = %.2f\n", pro[id - 1].proName, qty, qty * cost);
        total += qty * cost;
    }
    printf("Total Bill: %.2f\n", total);

    bid++;
}

void displayAllBills() {
    if (bid == 0) {
        printf("No bills available.\n");
        return;
    }

    for (int i = 0; i < bid; i++) {
        int custId = bill[i].cuID;
        printf("\n===== Bill %d =====\n", i + 1);

        // Show Customer Info
        for (int j = 0; j < cid; j++) {
            if (cus[j].cusId == custId) {
                printf("Customer ID: %d\n", cus[j].cusId);
                printf("Customer Name: %s\n", cus[j].cusName);
                printf("Phone: %s\n", cus[j].cusPhno);
                break;
            }
        }

        float total = 0;
        // Show Products in this bill
        for (int k = 0; k < bill[i].n; k++) {
            int pid = bill[i].itm[k].itmId;
            int qty = bill[i].itm[k].itmqua;
            float cost = pro[pid - 1].proCost;
            printf("Product: %s | Quantity: %d | Cost: %.2f\n",
                   pro[pid - 1].proName, qty, qty * cost);
            total += qty * cost;
        }
        printf("Total: %.2f\n", total);
    }
}

int main() {
    while (1) {
        int n;
        printf("\n========= MENU =========\n");
        printf("1) Create Customer\n");
        printf("2) Display Customers\n");
        printf("3) Enter Product\n");
        printf("4) Display Products\n");
        printf("5) Create Bill\n");
        printf("6) Identify Customer by ID\n");
        printf("7) Display All Bills\n");
        printf("0) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                createCustomer();
                break;
            case 2:
                displayCustomers();
                break;
            case 3:
                enterProduct();
                break;
            case 4:
                displayProducts();
                break;
            case 5:
                createBill();
                break;
            case 6:
                identifyCustomerByID();
                break;
            case 7:
                displayAllBills();
                break;
            case 0:
                printf("Exiting Program. Thank You!\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}