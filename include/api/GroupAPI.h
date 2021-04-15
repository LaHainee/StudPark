class GroupAPI : API {
  public:
      GroupAPI();
      static std::string GetGroupMembers();
	  static std::string AddGroupMembers();    // Для старосты
	  static std::string DeleteGroupMember();  // Для старосты
      static std::string ExportGroupList();    // Ссылка на скачивание csv
      static std::string AddJournalEntry();    // Проставление посещаемости от лица старосты
      static std::string CreateLabQueue();     // Создать очередь на лабы
      static std::string EditLabQueue();       // Кто-то поменялся или сдал (отправляется в конец очереди или вылетает)
  private:
      std::string createCsvFromData();  // Шаблонный метод
}
