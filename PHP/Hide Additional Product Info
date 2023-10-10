function hide_additional_product_info() {
    // Check if we are on a single product page
    if (is_product()) {
        // Hide the additional information tab
        remove_action('woocommerce_product_tabs', 'woocommerce_product_additional_information_tab', 10);
    }
}
add_action('wp', 'hide_additional_product_info');
