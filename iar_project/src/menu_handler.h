#ifndef _MENU_HANDLER_H
#define _MENU_HANDLER_H

#include "key_handler.h"
typedef enum
{
  MAIN_MODE = 0,
  GRAPH_MODE,
  GRAPH_MODE_10M,//10 minute
  MENU_MODE
}Mode_Status_Type;

#define EXIT_ITEM 0

/*
//��������� ���� ���� � ������������ �������� ��������� (menu_items_number[])
enum
{
  MAIN_MENU = 0,
  MENU_2,
  MENUS_COUNT //��������� ������� - ����� ���� � ������������ �������� �������
};
*/



//����� ���� ���������� ����
typedef enum
{
  MENU_LIST = 0,//��� ����, ���������� ������ ����������
  MENU_SUBITEM,//��� �������� ����
  MENU_CHANGE_ITEM,//��� ����� ����, ��� ����� ���-�� ������ (����������� - � ����)
  MENU_INFO_ITEM,//��� ����� ����, ��� ����� �������� ���������� (����������� - � ������� �����)
  MENU_GOBACK_ITEM,//��� ����� ����, ������������ � ���������� ����
}Menu_Item_Mode_Type;

typedef struct
{
  uint8_t item_number;//���������� ����� ������ ����
  const char     *name;//�������� ������
  uint8_t menu_number;//����� ����, � �������� ����������� �����
  uint8_t next_item;//����� ���������� ������ (������ ��� ��������� ����)
  uint8_t menu_position;//����� ������� � ������� ����
  Menu_Item_Mode_Type item_mode;//��� ���������
} Menu_Item_Type;

void modes_handler(void);
void process_key_action(Key_Status_Type key_stat);
void prosess_key_press_in_menu(Key_Status_Type key_stat);
void menu_item_press(Key_Status_Type key_stat);

void menu_subitem_press(Key_Status_Type key_stat);
uint8_t get_current_item_number(void);
uint8_t get_menu_items_count(void);
void show_menus(void);


void show_main_mode(void);
void show_graph_mode(void);
void show_graph_mode_10min(void);
void show_menu_items(void);
void show_info1(void);
void show_reboot_menu(void);

void fill_status_string(void);

void draw_vert_line(uint8_t x, uint8_t start, uint8_t height);
void draw_vert_dots(uint8_t x);
inline void set_point(uint8_t x, uint8_t y);
void draw_bar(uint16_t *data);
void draw_time_markers(uint8_t period);




#endif
