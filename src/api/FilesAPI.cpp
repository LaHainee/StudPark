API::Response FilesAPI::Share(std::map<std::string, std::string> &data) {
    const uint shareID = Sharing::Share(data);
    // Render success page and return it
}
 
/* Можно просматривать свои файлы, а можно чужие. Если чужие, в запросе надо
 * получить "чьи файлы смотрим", после чего получить листинг открытых файлов 
 * другого пользователя.
 */
API::Response FilesAPI::List(std::map<std::string, std::string> &data) {
    const std::map<std::string, std::string> files = Files::GetFiles(data);
    // Render file list page and return it
}
