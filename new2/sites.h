#define _CRT_SECURE_NO_WARNINGS
//#include <bsoncxx/json.hpp>
//#include <mongocxx/client.hpp>
//#include <mongocxx/instance.hpp>
#ifndef SITES_H
#define SITES_H
#include <iostream>
#include <string>
#include <vector>

std::string AddVector(std::vector<std::string>& products, std::vector<std::string>& description)
{
    if(products.size() % 9 == 0)
    {
        return "normal vector";
    }else if(products.size() < 9)
    {
        for (int i = 0; products.size() < 9; i++)
        {
            products.push_back("no product");
        }
    }
    else{
        for (int i = 0; i < products.size() % 9; i++)
        {
            products.push_back("no product");
        }
    }
    if(description.size() % 9 == 0)
    {
        return "normal vector";
    }else if(description.size() < 9)
    {
        for (int i = 0; description.size() < 9; i++)
        {
            description.push_back("no description");
        }
    }
    else
    {
        for (int i = 0; i < description.size() % 9; i++)
        {
            description.push_back("no description");
        }
    }
    return "done\n";
}

void PageRegister()
{

}

// logic functions

std::string LogIn(std::string status = "login")
{
    return R"###(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Личный кабинет</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 20px;
            background-color: #f4f4f4;
        }
        .container {
            max-width: 800px;
            margin: 0 auto;
            background-color: #fff;
            padding: 20px;
            border-radius: 5px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
        }
        h1 {
            font-size: 1.5em;
            margin-bottom: 20px;
        }
        form {
            display: flex;
            flex-direction: column;
        }
        input[type="text"] {
            margin-bottom: 10px;
            padding: 10px;
            font-size: 1em;
            border: 1px solid #ccc;
            border-radius: 5px;
            width: 100%;
            box-sizing: border-box;
        }
        button {
            background-color: #007bff;
            color: #fff;
            border: none;
            padding: 10px 20px;
            cursor: pointer;
            font-size: 1em;
            border-radius: 5px;
            margin-bottom: 10px;
            text-align: center;
        }
        button:hover {
            background-color: #0056b3;
        }
        a.button {
            display: inline-block;
            text-decoration: none;
            background-color: #007bff;
            color: #fff;
            padding: 10px 20px;
            border-radius: 5px;
            font-size: 1em;
            text-align: center;
            margin-top: 10px;
        }
        a.button:hover {
            background-color: #0056b3;
        }
        .button-container {
            display: flex;
            flex-direction: column;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>войдите в свой личный кабинет</h1>
        <form action="/checklogin" method="get">
            <input type="text" name="login" placeholder="Введите логин" required>
            <input type="text" name="password" placeholder="Введите пароль" required>
            <button type="submit">войти</button>
        </form>
        <a href="adduser"><button>зарегистрироваться</button></a>
    </div>
</body>
</html>

)###";

}

std::string siteHad(std::vector<std::vector<std::string>> fullvector, int page)
{
    std::vector<std::string> products = fullvector[0];
    std::vector<std::string> description = fullvector[1];

    std::cout<<AddVector(products, description);

    return R"###(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Client for online shop</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
            background-color: #f4f4f4;
        }
        header {
            background-color: #333;
            color: #fff;
            padding: 10px 0;
            text-align: center;
        }
        nav {
            display: flex;
            justify-content: center;
            background-color: #444;
        }
        nav a {
            color: #fff;
            padding: 14px 20px;
            text-decoration: none;
            text-align: center;
        }
        nav a:hover {
            background-color: #555;
        }
        .container {
            padding: 20px;
            display: flex;
            flex-wrap: wrap;
            justify-content: space-around;
        }
        .product {
            background-color: #fff;
            border: 1px solid #ddd;
            border-radius: 5px;
            padding: 15px;
            margin: 10px;
            text-align: center;
            flex-basis: calc(33.333% - 20px);
            box-sizing: border-box;
        }
        .product img {
            max-width: 100%;
            height: auto;
        }
        .product h2 {
            font-size: 1.5em;
            margin: 10px 0;
        }
        .product p {
            font-size: 1em;
            color: #555;
        }
        .product button {
            background-color: #28a745;
            color: #fff;
            border: none;
            padding: 10px 20px;
            cursor: pointer;
        }
        .product button:hover {
            background-color: #218838;
        }
        footer {
            background-color: #333;
            color: #fff;
            text-align: center;
            padding: 10px 0;

            width: 100%;
            bottom: 0;
        }
        .pagination {
          display: inline-block;
          margin-bottom: 1cm;
          text-align: center;
        }

        .pagination a {
          color: black;
          padding: 8px 16px;
          text-decoration: none;
          transition: background-color .3s;
          display: inline-block;
        }

        .pagination a.active {
          background-color: #4CAF50;
          color: white;
        }

        .pagination a:hover:not(.active) {background-color: #ddd;}
    </style>
</head>
<body>
    <header>
        <h1>Добро пожаловать в наш интернет-магазин</h1>
    </header>
    <nav>
        <a href="/personalarea">личный кабинет</a>
        <a href="#">Главная</a>
        <a href="#">Магазин</a>
        <a href="#">О нас</a>
        <a href="#">Контакты</a>
        <a href="/">выйти</a>
    </nav>
    <div class="container">
        <div class="product">
            <img src="https://via.placeholder.com/300" alt="Продукт 1">
            <h2>)###" + products[0 + (9 * page)] + R"###(</h2>
            <p>)###" + description[0 + (9 * page)] + R"###(</p>
            <button>Добавить в корзину</button>
        </div>
        <div class="product">
            <img src="https://via.placeholder.com/300" alt="Продукт 2">

            <form action="/product1" method="get">
                <input type="hidden" name="productname" value=")###" + products[1] + R"###(">
                <button type="submit"><h2>)###" + products[1 + (9 * page)] + R"###(</h2></button>
            </form>

            <p>)###" + description[1 + (9 * page)] + R"###(</p>
            <button>Добавить в корзину</button>
        </div>
        <div class="product">
            <img src="https://via.placeholder.com/300" alt="Продукт 3">
            <h2>)###" + products[2 + (9 * page)] + R"###(</h2>
            <p>)###" + description[2 + (9 * page)] + R"###(</p>
            <button>Добавить в корзину</button>
        </div>
        <div class="product">
            <img src="https://via.placeholder.com/300" alt="Продукт 4">
            <h2>)###" + products[3 + (9 * page)] + R"###(</h2>
            <p>)###" + description[3 + (9 * page)] + R"###(</p>
            <button>Добавить в корзину</button>
        </div>
        <div class="product">
            <img src="https://via.placeholder.com/300" alt="Продукт 5">
            <h2>)###" + products[4 + (9 * page)] + R"###(</h2>
            <p>)###" + description[4 + (9 * page)] + R"###(</p>
            <button>Добавить в корзину</button>
        </div>
        <div class="product">
            <img src="https://via.placeholder.com/300" alt="Продукт 6">
            <h2>)###" + products[5 + (9 * page)] + R"###(</h2>
            <p>)###" + description[5 + (9 * page)] + R"###(</p>
            <button>Добавить в корзину</button>
        </div>
        <div class="product">
            <img src="https://via.placeholder.com/300" alt="Продукт 7">
            <h2>)###" + products[6 + (9 * page)] + R"###(</h2>
            <p>)###" + description[6 + (9 * page)] + R"###(</p>
            <button>Добавить в корзину</button>
        </div>
        <div class="product">
            <img src="https://via.placeholder.com/300" alt="Продукт 8">
            <h2>)###" + products[7 + (9 * page)] + R"###(</h2>
            <p>)###" + description[7 + (9 * page)] + R"###(</p>
            <button>Добавить в корзину</button>
        </div>
        <div class="product">
            <img src="https://via.placeholder.com/300" alt="Продукт 9">
            <h2>)###" + products[8 + (9 * page)] + R"###(</h2>
            <p>О)###" + description[8 + (9 * page)] + R"###(</p>
            <button>Добавить в корзину</button>
        </div>
    </div>
    <div class="pagination">
      <a href="/pagedown">&laquo;</a>
      <a href="#" class="active">)###" + std::to_string(page) + R"###(</a>
      <a href="/pageup">&raquo;</a>
    </div>
    <footer>
        &copy; 2024 Интернет-магазин. Все права защищены.
    </footer>
</body>
</html>
)###";
}

std::string productPage(std::string productname = "no_product",
                        std::string description = "no_description"
                        /*std::vector<std::vector<std::string>> comments разберусь*/)
{

    return R"###(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Страница продукта</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
            background-color: #f4f4f4;
        }
        header {
            background-color: #333;
            color: #fff;
            padding: 10px 0;
            text-align: center;
        }
        nav {
            display: flex;
            justify-content: center;
            background-color: #444;
        }
        nav a {
            color: #fff;
            padding: 14px 20px;
            text-decoration: none;
            text-align: center;
        }
        nav a:hover {
            background-color: #555;
        }
        .container {
            padding: 20px;
            max-width: 800px;
            margin: 0 auto;
            background-color: #fff;
            border: 1px solid #ddd;
            border-radius: 5px;
        }
        .product-img {
            text-align: center;
        }
        .product-img img {
            max-width: 100%;
            height: auto;
            border-radius: 5px;
        }
        .product-info {
            margin-top: 20px;
        }
        .product-title {
            font-size: 2em;
            margin-bottom: 10px;
        }
        .product-description {
            font-size: 1.2em;
            color: #555;
        }
        .reviews {
            margin-top: 30px;
        }
        .review {
            border-top: 1px solid #ddd;
            padding-top: 10px;
            margin-top: 10px;
        }
        .review h3 {
            margin: 0;
            font-size: 1.5em;
        }
        .review p {
            margin: 5px 0;
            color: #777;
        }
        .review span {
            display: block;
            font-size: 0.9em;
            color: #999;
        }
        footer {
            background-color: #333;
            color: #fff;
            text-align: center;
            padding: 10px 0;
            position: fixed;
            width: 100%;
            bottom: 0;
        }
    </style>
</head>
<body>
    <header>
        <h1>Интернет-магазин</h1>
    </header>
    <nav>
        <a href="#">Главная</a>
        <a href="#">Магазин</a>
        <a href="#">О нас</a>
        <a href="#">Контакты</a>
    </nav>
    <div class="container">
        <div class="product-img">
            <img src="https://via.placeholder.com/600x400" alt="Изображение продукта">
        </div>
        <div class="product-info">
            <h2 class="product-title">)###" + productname + R"###(</h2>
            <p class="product-description">)###" + description + R"###(</p>
        </div>
        <div class="reviews">
            <h2>Отзывы</h2>
            <div class="review">
                <h3>Отличный продукт!</h3>
                <p>Я очень доволен этим продуктом. Он превзошел все мои ожидания!</p>
                <span>Автор: Иван Иванов</span>
                <span>Дата: 10 мая 2024</span>
            </div>
            <div class="review">
                <h3>Хорошее качество</h3>
                <p>Продукт соответствует описанию, хорошее качество. Рекомендую!</p>
                <span>Автор: Анна Смирнова</span>
                <span>Дата: 12 мая 2024</span>
            </div>
            <div class="review">
                <h3>Не очень доволен</h3>
                <p>Качество среднее, ожидал большего. Доставка была долгой.</p>
                <span>Автор: Петр Петров</span>
                <span>Дата: 15 мая 2024</span>
            </div>
        </div>
    </div>
    <footer>
        &copy; 2024 Интернет-магазин. Все права защищены.
    </footer>
</body>
</html>

)###";
}

std::string PersonalArea()
{
    return R"###(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Личный кабинет</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 20px;
            background-color: #f4f4f4;
        }
        .container {
            max-width: 800px;
            margin: 0 auto;
            background-color: #fff;
            padding: 20px;
            border-radius: 5px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
        }
        img {
            max-width: 100%;
            height: auto;
        }
        button {
            background-color: #007bff;
            color: #fff;
            border: none;
            padding: 10px 20px;
            cursor: pointer;
            font-size: 1em;
            border-radius: 5px;
        }
        button:hover {
            background-color: #0056b3;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Личный кабинет</h1>
        <p><strong>Имя:</strong> Иван Иванов</p>
        <p><strong>Описание:</strong> Здесь может быть ваше описание</p>
        <p><strong>Отзывы:</strong> Здесь могут быть ваши отзывы</p>
        <img src="77856.jpg" alt="Ваша картинка">

        <a href="/hadsite"><button>Мои продукты</button></a>
        <a href="/addproduct"><button>добавить продукт</button></a>

    </div>
</body>
</html>

)###";
}

std::string AddProductSite()
{
    return R"###(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Личный кабинет</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 20px;
            background-color: #f4f4f4;
        }
        .container {
            max-width: 800px;
            margin: 0 auto;
            background-color: #fff;
            padding: 20px;
            border-radius: 5px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
        }
        h1 {
            font-size: 1.5em;
            margin-bottom: 20px;
        }
        form {
            display: flex;
            flex-direction: column;
        }
        input[type="text"] {
            margin-bottom: 10px;
            padding: 10px;
            font-size: 1em;
            border: 1px solid #ccc;
            border-radius: 5px;
            width: 100%;
            box-sizing: border-box;
        }
        button {
            background-color: #007bff;
            color: #fff;
            border: none;
            padding: 10px 20px;
            cursor: pointer;
            font-size: 1em;
            border-radius: 5px;
            margin-bottom: 10px;
            text-align: center;
        }
        button:hover {
            background-color: #0056b3;
        }
        a.button {
            display: inline-block;
            text-decoration: none;
            background-color: #007bff;
            color: #fff;
            padding: 10px 20px;
            border-radius: 5px;
            font-size: 1em;
            text-align: center;
            margin-top: 10px;
        }
        a.button:hover {
            background-color: #0056b3;
        }
        .button-container {
            display: flex;
            flex-direction: column;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Заполните форму для добавления товара</h1>
        <form action="/publicnewproduct" method="get">
            <input type="text" id="inputField" name="productname" placeholder="Введите название" required>
            <input type="text" id="inputField" name="productdescription" placeholder="Введите описание" required>
            <button type="submit">Добавить</button>
        </form>
        <div class="button-container">
            <a href="/personalarea" class="button">назад</a>
            <a href="/hadsite" class="button">на главную</a>
        </div>
    </div>
</body>
</html>

)###";
}

std::string AddUser()
{
    return R"###(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Личный кабинет</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 20px;
            background-color: #f4f4f4;
        }
        .container {
            max-width: 800px;
            margin: 0 auto;
            background-color: #fff;
            padding: 20px;
            border-radius: 5px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
        }
        h1 {
            font-size: 1.5em;
            margin-bottom: 20px;
        }
        form {
            display: flex;
            flex-direction: column;
        }
        input[type="text"] {
            margin-bottom: 10px;
            padding: 10px;
            font-size: 1em;
            border: 1px solid #ccc;
            border-radius: 5px;
            width: 100%;
            box-sizing: border-box;
        }
        button {
            background-color: #007bff;
            color: #fff;
            border: none;
            padding: 10px 20px;
            cursor: pointer;
            font-size: 1em;
            border-radius: 5px;
            margin-bottom: 10px;
            text-align: center;
        }
        button:hover {
            background-color: #0056b3;
        }
        a.button {
            display: inline-block;
            text-decoration: none;
            background-color: #007bff;
            color: #fff;
            padding: 10px 20px;
            border-radius: 5px;
            font-size: 1em;
            text-align: center;
            margin-top: 10px;
        }
        a.button:hover {
            background-color: #0056b3;
        }
        .button-container {
            display: flex;
            flex-direction: column;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>регистрация</h1>
        <form action="/publicnewuser" method="get">
            <input type="text" id="inputField" name="login" placeholder="придумайте логин" required>
            <input type="text" id="inputField" name="password" placeholder="придумайте пароль" required>
            <input type="text" id="inputField" name="description" placeholder="опишите себя">
            <button type="submit">зарегистрироваться</button>
        </form>
        <div class="button-container">
            <a href="/hadsite" class="button">на главную</a>
        </div>
    </div>
</body>
</html>

)###";
}

#endif // SITES_H
