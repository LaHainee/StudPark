class FilesAPI : API {
  public:
    FilesAPI() = default;
    static std::string Share();
    static std::string List();  // Интерфейс "проводника". Листинг файлов. Пока без папок.
}	
