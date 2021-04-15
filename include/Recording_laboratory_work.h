#ifndef C___RECORDING_LABORATORY_WORK_H
#define C___RECORDING_LABORATORY_WORK_H

class Recording_laboratory_work {
public:
    explicit Recording_laboratory_work(
            int recording_id,
            int user_id,
            int subject_id,
            time_t date_lab,
            int group_id,
            unsigned int user_position) :
            id(recording_id),
            user(user_id),
            subject(subject_id),
            date_lab(date_lab),
            group(group_id),
            position(user_position) {}
    Recording_laboratory_work() {}
    static void AddRecording(int user_id, int subject_id, time_t date_lab, int group_id, unsigned int user_position);
    void DeleteRecording(int lab_id);
    static void UpdateRecording(int recording_id, int user_id, int subject_id, time_t date_lab, int group_id,
                                unsigned int user_position);
    static Recording_laboratory_work GetRecording(int user_id, int subject_id);
private:
    int id;
    unsigned int position;
    time_t date_lab;
    int subject;
    int group;
    int user;
};

#endif //C___RECORDING_LABORATORY_WORK_H
