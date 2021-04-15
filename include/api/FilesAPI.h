class FilesAPI : API {
  public:
    FilesAPI() = default;
    static API::Response Share();
    static API::Response List();  // Интерфейс "проводника". Листинг файлов. Пока без папок.
}	
