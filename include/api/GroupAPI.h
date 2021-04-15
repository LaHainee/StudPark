class GroupAPI : API {
  public:
      GroupAPI();
      static API::Response GetGroupMembers();
      static API::Response AddGroupMembers();    // Для старосты
      static API::Response DeleteGroupMember();  // Для старосты
      static API::Response ExportGroupList();    // Ссылка на скачивание csv
      static API::Response AddJournalEntry();    // Проставление посещаемости от лица старосты
      static API::Response CreateLabQueue();     // Создать очередь на лабы
      static API::Response EditLabQueue();       // Кто-то поменялся или сдал (отправляется в конец очереди или вылетает)
  private:
      std::string createCsvFromData();  // Шаблонный метод
}
