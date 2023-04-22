// Inventory Management class
class InventoryManagement {
public:
    void checkInventory(int productId) {
        // implementation
    }
};

// Order Processing class
class OrderProcessing {
public:
    void createOrder(int productId, int quantity) {
        // implementation
    }
};

// Payment Processing class
class PaymentProcessing {
public:
    void processPayment(double amount) {
        // implementation
    }
};

// Purchase Facade class
class PurchaseFacade {
private:
    InventoryManagement inventoryManagement;
    OrderProcessing orderProcessing;
    PaymentProcessing paymentProcessing;
public:
    void purchaseProduct(int productId, int quantity, double amount) {
        inventoryManagement.checkInventory(productId);
        orderProcessing.createOrder(productId, quantity);
        paymentProcessing.processPayment(amount);
    }
};
