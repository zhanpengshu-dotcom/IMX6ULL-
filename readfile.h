#ifndef READFILE_H
#define READFILE_H

#include <QObject>

class readfile : public QObject
{
    Q_OBJECT
public:
    explicit readfile(QObject *parent = nullptr);

   /*  int read_file_data_u8(char *FileName,unsigned char *data);
    int read_file_data_u16(char *FileName,unsigned short *data);
    int read_file_data_s16(char *FileName,short *data);
    int read_file_data_int32(char *FileName,int *data); */

    int read_file_data_u8(const char *FileName, unsigned char *data);
    int read_file_data_u16(const char *FileName, unsigned short *data);
    int read_file_data_s16(const char *FileName, short *data);
    int read_file_data_int32(const char *FileName, int *data);
    int read_file_data_int32_pair(const char *FileName, int *data);


signals:

};

#endif // READFILE_H
