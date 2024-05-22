#define _CRT_SECURE_NO_WARNINGS
#include <QCoreApplication>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <iostream>
#include <string>   // для stoi и to_string
#include "httplib.h"
#include "sites.h"
#include "json.hpp"
using json = nlohmann::json;
using namespace httplib;

mongocxx::collection collection;

namespace hide
{
std::string login = "asan";
std::string password = "kali";
int page = 0;
int maxpage = 0;
}

std::string Cleaner(std::string line)
{
    std::string line1;

    for(char& sign : line)
    {
        if(sign != '"')
        {
            line1.push_back(sign);
        }
    }
    return line1;
}

void handlerAddproductSite(const Request& req, Response& res)
{
    auto productName = req.has_param("productName") ? req.get_param_value("productName") : "no_name";
    auto description = req.has_param("description") ? req.get_param_value("description") : "no_deskription";

    res.set_content(AddProductSite(), "text/html");
}

// do it
void PublicProduct(const Request& req, Response& res)
{
    auto salesman = req.has_param("salesman") ? req.get_param_value("salesman") : "no_name";
    auto productName = req.has_param("productname") ? req.get_param_value("productname") : "no_product";
    auto description = req.has_param("productdescription") ? req.get_param_value("productdescription") : "no_deskription";

    std::string product = R"###({"type":"product",
                                "productName":")###" + productName + R"###(",
                            "productDeskription":")###" + description + R"###(",
                            "salesman":")###" + salesman + R"###(",
                            "status":""})###";

    auto doc = bsoncxx::from_json(product);
    collection.insert_one(doc.view());

    res.set_content(PersonalArea(), "text/html");
}

void PublicUser(const Request& req, Response& res)
{
    auto salesman = req.has_param("login") ? req.get_param_value("login") : "no_login";
    auto password = req.has_param("password") ? req.get_param_value("password") : "no_password";
    auto description = req.has_param("description") ? req.get_param_value("description") : "no_description";

    std::string product = R"###({"type":"salesman",
                                "salesman":")###" + salesman + R"###(",
                            "password":")###" + password + R"###(",
                            "description":")###" + description + R"###("})###";

    auto doc = bsoncxx::from_json(product);
    collection.insert_one(doc.view());

    res.set_content(LogIn(), "text/html");
}

// empty
void ParseProduct(std::vector<std::string>& products, std::vector<std::string>& descriptions, mongocxx::cursor& cursor)
{
    for (auto&& doc : cursor) {
        std::string doc_str = bsoncxx::to_json(doc);
        json doc_json = json::parse(doc_str);

        // Обработка возможных исключений при доступе к ключам
        try {
            std::string productName = doc_json.at("productName").get<std::string>();
            std::string productDescription = doc_json.at("productDeskription").get<std::string>();

            std::cout << productName << std::endl;
            std::cout << productDescription << std::endl;

            products.push_back(productName);
            descriptions.push_back(productDescription);
        } catch (json::exception& e) {
            std::cerr << "Error accessing key: " << e.what() << std::endl;
        }
    }

}

// срочно оптимизировать двойной сбор данных с базы (вынести парсер)
std::vector<std::vector<std::string>> GetProducts(int count, int page = 0)
{
    std::vector<std::vector<std::string>> fullvector;
    std::vector<std::string> products;
    std::vector<std::string> descriptions;

    auto allproduct = bsoncxx::from_json(R"###({"type":"product"})###");
    mongocxx::cursor cursor = collection.find(allproduct.view());

    ParseProduct(products, descriptions, cursor);

    hide::maxpage = (products.size() / 9) - 1;
    if(products.size() % 9 != 0)
    {
        hide::maxpage++;
    }

    fullvector.push_back(products);
    fullvector.push_back(descriptions);

    return fullvector;

}

std::string GetUser(std::string login)
{

    auto findername = bsoncxx::from_json(R"###({"salesman":")###" + login + R"###("})###");
    auto cursor = collection.find_one(findername.view());

    if(cursor)
    {
        auto doc = cursor->view();
        std::string line = bsoncxx::to_json(doc);
        json document = json::parse(line);

        return Cleaner(document["password"]);
    }
    return "no password";
}

void handlerAddUserSite(const Request& req, Response& res)
{
    res.set_content(AddUser(), "text/html");
}

void PrintLog(std::string log)
{
    std::cout<<'\n'<<log<<'\n';
}

void handlerLogin(const Request& req, Response& res)
{
    //auto a = req.has_param("a") ? std::stoi( req.get_param_value("a") ) : 0;
    //auto b = req.has_param("b") ? std::stoi( req.get_param_value("b") ) : 0;

    PrintLog("login");
    // PublicProduct("asan");
    res.set_content(LogIn(), "text/html");
}

void handlerHadSite(const Request& req, Response& res)
{
    hide::page = 0;
    int page = hide::page;
    res.set_content(siteHad(GetProducts(1), page), "text/html");
}

void PageUP(const Request& req, Response& res)
{
    int page = hide::page;
    if (hide::page + 1 <= hide::maxpage)
    {
        page = hide::page + 1;
        res.set_content(siteHad(GetProducts(1), page), "text/html");
    }
    res.set_content(siteHad(GetProducts(1), page), "text/html");

}
void PageDown(const Request& req, Response& res)
{
    int page = hide::page;
    if (hide::page - 1 >= 0)
    {
        page = hide::page - 1;
        res.set_content(siteHad(GetProducts(1), page), "text/html");
    }
    res.set_content(siteHad(GetProducts(1), page), "text/html");
}
// no products vector
void handlerCheckLogin(const Request& req, Response& res) {
    std::string login = req.has_param("login") ? req.get_param_value("login") : "nologin";
    std::string password = req.has_param("password") ? req.get_param_value("password") : "nopasswd";

    PrintLog(login);
    PrintLog(password);
    hide::password = GetUser(login);
    hide::login = login;

    if(/*login != hide::login || */password != hide::password)
    {
        PrintLog("check failed 78");
        res.set_content(LogIn("failed"), "text/html");
    }else
    {
        PrintLog("on had of site");
        handlerHadSite(req, res);
    }
}

void handlerProduct(const Request& req, Response& res)
{
    std::string loginname = req.has_param("loginname") ? req.get_param_value("loginname") : "0";
    std::string productname = req.has_param("productname") ? req.get_param_value("productname") : "0";

    PrintLog("product page");
    PrintLog(productname);
    res.set_content(productPage(productname, "description"), "text/html");
}

void handlerPersonalArea(const Request& req, Response& res)
{
    std::string loginname = req.has_param("loginname") ? req.get_param_value("loginname") : "0";
    std::string productname = req.has_param("productname") ? req.get_param_value("productname") : "0";

    res.set_content(PersonalArea(), "text/html");
}

int main() {
    mongocxx::instance inst{};
    const auto uri = mongocxx::uri{ "mongodb+srv://mongo_user:LXkEj4dJLpY19PT0@cluster0.6yzdyrb.mongodb.net/" };

    mongocxx::client connection{ uri };
    collection = connection["new"]["one"];

    Server svr;
    std::cout<<'\n'<<"server is start... "<<'\n';
    svr.Get("/", handlerLogin);
    svr.Get("/checklogin", handlerCheckLogin);
    svr.Get("/product1", handlerProduct);
    svr.Get("/personalarea", handlerPersonalArea);
    svr.Get("/hadsite", handlerHadSite);
    svr.Get("/addproduct", handlerAddproductSite);
    svr.Get("/publicnewproduct", PublicProduct);
    svr.Get("/adduser", handlerAddUserSite);
    svr.Get("/publicnewuser", PublicUser);
    svr.Get("/pageup", PageUP);
    svr.Get("/pagedown", PageDown);
    svr.listen("0.0.0.0", 8082);
}
