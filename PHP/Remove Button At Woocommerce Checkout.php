function cartflow_add_remove_button_to_checkout( $product_name, $cart_item, $cart_item_key ) {
    if ( is_checkout() ) {
        $product_id = $cart_item['product_id'];
        $remove_link = sprintf(
            '<a href="%s" class="remove-product" data-product_id="%s" data-cart_item_key="%s">%s</a>',
            esc_url( wc_get_cart_remove_url( $cart_item_key ) ),
            esc_attr( $product_id ),
            esc_attr( $cart_item_key ),
            __('Remove', 'your-text-domain') // Replace 'your-text-domain' with your theme or plugin text domain
        );

        return $product_name . ' ' . $remove_link;
    }

    return $product_name;
}
add_filter( 'woocommerce_cart_item_name', 'cartflow_add_remove_button_to_checkout', 10, 3 );
