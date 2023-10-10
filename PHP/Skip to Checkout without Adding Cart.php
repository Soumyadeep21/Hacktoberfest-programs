//skip cart and go straight to checkout
add_filter( 'woocommerce_add_to_cart_redirect', 'skip_wc_cart' ); 
function skip_wc_cart() {
   return wc_get_checkout_url();
}

//customize add to cart text
add_filter( 'woocommerce_product_single_add_to_cart_text', 'lw_cart_btn_text' );
add_filter( 'woocommerce_product_add_to_cart_text', 'lw_cart_btn_text' );
//Changing Add to Cart text to Buy It Now 
function lw_cart_btn_text() {
 return __( 'Buy It Now', 'woocommerce' );
}

//remove the "has been added to your cart" message
add_filter( 'wc_add_to_cart_message_html', '__return_false' );
