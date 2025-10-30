#include "product.h"
#include <iostream>
#include <vector>
using namespace std;

// Print every single attribute
void Product::print() const {
    cout << "---------------------------------------------\n";
    cout << "Unique ID: " << unique_id << "\n";
    cout << "Product Name: " << product_name << "\n";
    cout << "Brand Name: " << brand_name << "\n";
    cout << "ASIN: " << asin << "\n";
    cout << "Category: " << category << "\n";
    cout << "UPC/EAN Code: " << upc_ean_code << "\n";
    cout << "List Price: " << list_price << "\n";
    cout << "Selling Price: " << selling_price << "\n";
    cout << "Quantity: " << quantity << "\n";
    cout << "Model Number: " << model_number << "\n";
    cout << "About Product: " << about_product << "\n";
    cout << "Product Specification: " << product_specification << "\n";
    cout << "Technical Details: " << technical_details << "\n";
    cout << "Shipping Weight: " << shipping_weight << "\n";
    cout << "Product Dimensions: " << product_dimensions << "\n";
    cout << "Image: " << image << "\n";
    cout << "Variants: " << variants << "\n";
    cout << "SKU: " << sku << "\n";
    cout << "Product URL: " << product_url << "\n";
    cout << "Stock: " << stock << "\n";
    cout << "Product Details: " << product_details << "\n";
    cout << "Dimensions: " << dimensions << "\n";
    cout << "Color: " << color << "\n";
    cout << "Ingredients: " << ingredients << "\n";
    cout << "Direction to Use: " << direction_to_use << "\n";
    cout << "Is Amazon Seller: " << is_amazon_seller << "\n";
    cout << "Size/Quantity Variant: " << size_quantity_variant << "\n";
    cout << "Product Description: " << product_description << "\n";
    cout << "---------------------------------------------\n";
}
