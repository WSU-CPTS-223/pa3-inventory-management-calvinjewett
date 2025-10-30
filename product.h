#ifndef AMAZONPRODUCT_H
#define AMAZONPRODUCT_H

#include <string>
using namespace std;

class Product {
private:
    string unique_id;
    string product_name;
    string brand_name;
    string asin;
    string category;
    string upc_ean_code;
    string list_price;
    string selling_price;
    string quantity;
    string model_number;
    string about_product;
    string product_specification;
    string technical_details;
    string shipping_weight;
    string product_dimensions;
    string image;
    string variants;
    string sku;
    string product_url;
    string stock;
    string product_details;
    string dimensions;
    string color;
    string ingredients;
    string direction_to_use;
    string is_amazon_seller;
    string size_quantity_variant;
    string product_description;

public:
    // Default constructor
    Product() = default;

    // Full constructor
    Product(const string& unique_id,
                  const string& product_name,
                  const string& brand_name,
                  const string& asin,
                  const string& category,
                  const string& upc_ean_code,
                  const string& list_price,
                  const string& selling_price,
                  const string& quantity,
                  const string& model_number,
                  const string& about_product,
                  const string& product_specification,
                  const string& technical_details,
                  const string& shipping_weight,
                  const string& product_dimensions,
                  const string& image,
                  const string& variants,
                  const string& sku,
                  const string& product_url,
                  const string& stock,
                  const string& product_details,
                  const string& dimensions,
                  const string& color,
                  const string& ingredients,
                  const string& direction_to_use,
                  const string& is_amazon_seller,
                  const string& size_quantity_variant,
                  const string& product_description)
        : unique_id(unique_id),
          product_name(product_name),
          brand_name(brand_name),
          asin(asin),
          category(category),
          upc_ean_code(upc_ean_code),
          list_price(list_price),
          selling_price(selling_price),
          quantity(quantity),
          model_number(model_number),
          about_product(about_product),
          product_specification(product_specification),
          technical_details(technical_details),
          shipping_weight(shipping_weight),
          product_dimensions(product_dimensions),
          image(image),
          variants(variants),
          sku(sku),
          product_url(product_url),
          stock(stock),
          product_details(product_details),
          dimensions(dimensions),
          color(color),
          ingredients(ingredients),
          direction_to_use(direction_to_use),
          is_amazon_seller(is_amazon_seller),
          size_quantity_variant(size_quantity_variant),
          product_description(product_description)
    {}

    // Getters
    string getUniqueId() const { return unique_id; }
    string getProductName() const { return product_name; }
    string getBrandName() const { return brand_name; }
    string getAsin() const { return asin; }
    string getCategory() const { return category; }
    string getUpcEanCode() const { return upc_ean_code; }
    string getListPrice() const { return list_price; }
    string getSellingPrice() const { return selling_price; }
    string getQuantity() const { return quantity; }
    string getModelNumber() const { return model_number; }
    string getAboutProduct() const { return about_product; }
    string getProductSpecification() const { return product_specification; }
    string getTechnicalDetails() const { return technical_details; }
    string getShippingWeight() const { return shipping_weight; }
    string getProductDimensions() const { return product_dimensions; }
    string getImage() const { return image; }
    string getVariants() const { return variants; }
    string getSku() const { return sku; }
    string getProductUrl() const { return product_url; }
    string getStock() const { return stock; }
    string getProductDetails() const { return product_details; }
    string getDimensions() const { return dimensions; }
    string getColor() const { return color; }
    string getIngredients() const { return ingredients; }
    string getDirectionToUse() const { return direction_to_use; }
    string getIsAmazonSeller() const { return is_amazon_seller; }
    string getSizeQuantityVariant() const { return size_quantity_variant; }
    string getProductDescription() const { return product_description; }

    // Setters
    void setUniqueId(const string& val) { unique_id = val; }
    void setProductName(const string& val) { product_name = val; }
    void setBrandName(const string& val) { brand_name = val; }
    void setAsin(const string& val) { asin = val; }
    void setCategory(const string& val) { category = val; }
    void setUpcEanCode(const string& val) { upc_ean_code = val; }
    void setListPrice(const string& val) { list_price = val; }
    void setSellingPrice(const string& val) { selling_price = val; }
    void setQuantity(const string& val) { quantity = val; }
    void setModelNumber(const string& val) { model_number = val; }
    void setAboutProduct(const string& val) { about_product = val; }
    void setProductSpecification(const string& val) { product_specification = val; }
    void setTechnicalDetails(const string& val) { technical_details = val; }
    void setShippingWeight(const string& val) { shipping_weight = val; }
    void setProductDimensions(const string& val) { product_dimensions = val; }
    void setImage(const string& val) { image = val; }
    void setVariants(const string& val) { variants = val; }
    void setSku(const string& val) { sku = val; }
    void setProductUrl(const string& val) { product_url = val; }
    void setStock(const string& val) { stock = val; }
    void setProductDetails(const string& val) { product_details = val; }
    void setDimensions(const string& val) { dimensions = val; }
    void setColor(const string& val) { color = val; }
    void setIngredients(const string& val) { ingredients = val; }
    void setDirectionToUse(const string& val) { direction_to_use = val; }
    void setIsAmazonSeller(const string& val) { is_amazon_seller = val; }
    void setSizeQuantityVariant(const string& val) { size_quantity_variant = val; }
    void setProductDescription(const string& val) { product_description = val; }

    // Print info
    void print() const;
};

#endif
