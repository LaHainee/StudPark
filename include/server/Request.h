#ifndef SERVER_REQUEST_H
#define SERVER_REQUEST_H

#include <string>
#include <unordered_map>

class Request {
public:
    explicit Request(const std::string &request);
    std::string method();
    std::string header(const std::string& key);
    std::string path();
    std::string data(const std::string& key);
    std::string data();
    std::string cookie(const std::string & key);
    std::string dataPost(const std::string & key);
    std::unordered_multimap<std::string, std::string> dataTable();

private:
    std::string _method;
    std::string _path;
    std::string body;
    std::unordered_multimap<std::string, std::string> headers;
    std::unordered_multimap<std::string, std::string> _data;
    std::unordered_map<std::string, std::string> cookies;
    std::unordered_map<std::string, std::string> dataPosts;

    void parseStartLine(const std::string::const_iterator &begin, const std::string::const_iterator &end);
    void parseHeaders(const std::string::const_iterator &begin, const std::string::const_iterator &end);
    void parseCookies();
    void parseDataPost();
    void parseDataFromPath();
    void parseDataFromBody(const std::string::const_iterator &begin, const std::string::const_iterator &end);
    std::string urlDecode(const std::string::const_iterator &begin, const std::string::const_iterator &end);
    std::string urlDecode(const std::string &url);

    void replacePlusToSpace(std::string &str);
};

#endif //SERVER_REQUEST_H
