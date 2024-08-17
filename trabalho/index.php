<?php
require_once('inc/topo.php');
session_start();

$cupons = ['DESC10', 'DESC30'];
$cupom = '';
$desconto = 0;

$_SESSION['product-name'] = 'Placa de Vídeo Asus Dual NVIDIA GeForce RTX 2070 EVO V2 OC Edition, 8GB, GDDR6';
$_SESSION['preco_prod'] = 'R$ 2.949,90';
$preco_prod = 2949.90;

if (!isset($_SESSION['contador'])) {
    $_SESSION['contador'] = 1;
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (isset($_POST['aumentar'])) {
        $_SESSION['contador']++;
    } elseif (isset($_POST['diminuir'])) {
        if ($_SESSION['contador'] > 1) {
            $_SESSION['contador']--;
        }
    } elseif (isset($_POST['remover'])) {
        unset($_SESSION['product-name']);
        unset($_SESSION['contador']);
        $_SESSION['subtotal'] = 0;
    }

    if (isset($_POST['cupom'])) {
        $cupom = $_POST['cupom'];
        if (in_array($cupom, $cupons)) {
            if ($cupom == 'DESC10') {
                $desconto = 0.10;
            } elseif ($cupom == 'DESC30') {
                $desconto = 0.30;
            }
            $_SESSION['subtotal'] = $_SESSION['contador'] * $preco_prod * (1 - $desconto);
        }
    }
}
if ($desconto > 0) {
   $_SESSION['subtotal'] = $_SESSION['contador'] * $preco_prod * (1 - $desconto);
} else {
   $_SESSION['subtotal'] = $_SESSION['contador'] * $preco_prod;
}

?>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Index PHP</title>
    <link href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css" rel="stylesheet">
</head>
<body>
    <div class="main_content">
        <div class="section">
            <div class="container">
                <div class="row">
                    <div class="col-12">
                        <div class="table-responsive shop_cart_table">
                            <table class="table">
                                <thead>
                                    <tr>
                                        <th class="product-thumbnail"></th>
                                        <th class="product-name">Produto</th>
                                        <th class="product-price">Preço</th>
                                        <th class="product-quantity">Quantidade</th>
                                        <th class="subtotal">Subtotal</th>
                                        <th class="product-remove">Remove</th>
                                    </tr>
                                </thead>
                                <tbody>
                                    <?php if (isset($_SESSION['product-name'])) { ?>
                                    <tr>
                                        <td class="product-thumbnail">
                                            <a href=""><img src="http://localhost/ifc/trabalho/img/produto.jpg" alt="Placa de Vídeo Asus Dual NVIDIA GeForce RTX 2070 EVO V2 OC Edition, 8GB, GDDR6"></a>
                                        </td>
                                        <td class="product-name" data-title="Product">
                                            <a href=""><?=$_SESSION['product-name']?></a>
                                        </td>
                                        <td class="product-price" data-title="Price"><?=$_SESSION['preco_prod']?></td>
                                        <td class="product-quantity" data-title="Quantity">
                                            <form method="post" action="" class="d-inline">
                                                <button type="submit" name="aumentar" class="btn btn-success">+</button>
                                                <input type="text" disabled name="qtde_pedido_item" value="<?=$_SESSION['contador']?>" title="Qty" class="qty" size="4">
                                                <button type="submit" name="diminuir" class="btn btn-danger">-</button>
                                            </form>
                                        </td>
                                        <td class="subtotal" data-title="Total">R$ <?=number_format($_SESSION['subtotal'], 2, ',', '.')?></td>
                                        <td class="product-remove">
                                            <form method="post" action="" class="d-inline">
                                                <button type="submit" name="remover" class="btn btn-danger">X</button>
                                            </form>
                                        </td>
                                    </tr>
                                    <?php } ?>
                                </tbody>
                                <tfoot>
                                    <tr>
                                        <td colspan="6" class="px-0">
                                            <form method="post" action="" class="text-center mt-4">
                                                <div class="row no-gutters align-items-center">
                                                    <div class="col-lg-12 col-md-12 mb-12 mb-md-12">
                                                        <div class="coupon field_form input-group">
                                                            <input type="text" class="form-control form-control-sm" placeholder="Código do cupom" id="cupom" name="cupom" value="">
                                                            <div class="input-group-append">
                                                                <button class="btn btn-fill-out btn-sm" type="submit">Aplicar cupom</button>
                                                            </div>
                                                        </div>
                                                    </div>
                                                </div>
                                            </form>
                                        </td>
                                    </tr>
                                </tfoot>
                            </table>
                            <a href="http://localhost/trabalho/login.php" class="btn btn-fill-out">Concluir compra</a>
                        </div>
                    </div>
                </div>
                <div class="row">
                    <div class="col-12">
                        <div class="medium_divider"></div>
                        <div class="divider center_icon"><i class="ti-shopping-cart-full"></i></div>
                        <div class="medium_divider"></div>
                    </div>
                </div>
            </div>
        </div>
    </div>
</body>
</html>
