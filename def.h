#pragma once
#include <graphics.h>
#include "utli.h"
#include "atlas.h"

/*
Ϊ�������Դ����ȫ�ֱ���
��������:
img_:ͼƬ��Դ
atlas_:ͼ����Դ

*/

IMAGE img_menu_background;//���˵�����

IMAGE img_VS;//vs������ͼƬ
IMAGE img_1p;//1p�ı�ͼ
IMAGE img_2p;//2p�ı�ͼ
IMAGE img_1p_desc;//1p��λ����ͼ
IMAGE img_2p_desc;//2p��λ����ͼ
IMAGE img_gravestone_left;//�������Ĺ��ͼ
IMAGE img_gravestone_right;//Ĺ������
IMAGE img_selector_background;//ѡ�ǽ��汳��ͼ
IMAGE img_selector_tip;//ѡ�ǽ�����ʾ��Ϣ�ı�ͼ

IMAGE img_1P_selector_btn_idle_left;            // 1P ����ѡ��ťĬ��״̬ͼƬ
IMAGE img_1P_selector_btn_idle_right;           // 1P ����ѡ��ťĬ��״̬ͼƬ
IMAGE img_1P_selector_btn_down_left;            // 1P ����ѡ��ť����״̬ͼƬ
IMAGE img_1P_selector_btn_down_right;           // 1P ����ѡ��ť����״̬ͼƬ

IMAGE img_2P_selector_btn_idle_left;            // 2P ����ѡ��ťĬ��״̬ͼƬ
IMAGE img_2P_selector_btn_idle_right;           // 2P ����ѡ��ťĬ��״̬ͼƬ
IMAGE img_2P_selector_btn_down_left;            // 2P ����ѡ��ť����״̬ͼƬ
IMAGE img_2P_selector_btn_down_right;           // 2P ����ѡ��ť����״̬ͼƬ

IMAGE img_peashooter_selector_background_left;  // ѡ�ǽ��泯����������ֱ���ͼƬ
IMAGE img_peashooter_selector_background_right; // ѡ�ǽ��泯���ҵ������ֱ���ͼƬ

IMAGE img_sunflower_selector_background_left;   // ѡ�ǽ��泯��������տ�����ͼƬ
IMAGE img_sunflower_selector_background_right;  // ѡ�ǽ��泯���ҵ����տ�����ͼƬ

IMAGE img_sky;                                  // ���ͼƬ
IMAGE img_hills;                                // ɽ��ͼƬ
IMAGE img_platform_large;                       //����ƽ̨ͼƬ
IMAGE img_platform_small;                       //С��ƽ̨ͼƬ

IMAGE img_1P_cursor;                            // 1P ָʾ���ͼƬ
IMAGE img_2P_cursor;                            // 2P ָʾ���ͼƬ

Atlas atlas_peashooter_idle_left;               // �����ֳ������Ĭ�϶���ͼ��
Atlas atlas_peashooter_idle_right;              // �����ֳ����ҵ�Ĭ�϶���ͼ��
Atlas atlas_peashooter_run_left;                // �����ֳ�������ܲ�����ͼ��
Atlas atlas_peashooter_run_right;               // �����ֳ����ҵ��ܲ�����ͼ��
Atlas atlas_peashooter_attack_ex_left;             // �����ֳ�����Ĺ�������ͼ��
Atlas atlas_peashooter_attack_ex_right;            // �����ֳ����ҵĹ�������ͼ��
Atlas atlas_peashooter_die_left;                // �����ֳ��������������ͼ��
Atlas atlas_peashooter_die_right;               // �����ֳ����ҵ���������ͼ��

Atlas atlas_sunflower_idle_left;                // ���տ��������Ĭ�϶���ͼ��
Atlas atlas_sunflower_idle_right;               // ���տ������ҵ�Ĭ�϶���ͼ��
Atlas atlas_sunflower_run_left;                 // ���տ���������ܲ�����ͼ��
Atlas atlas_sunflower_run_right;                // ���տ������ҵ��ܲ�����ͼ��
Atlas atlas_sunflower_attack_ex_left;              // ���տ�������Ĺ�������ͼ��
Atlas atlas_sunflower_attack_ex_right;             // ���տ������ҵĹ�������ͼ��
Atlas atlas_sunflower_die_left;                 // ���տ����������������ͼ��
Atlas atlas_sunflower_die_right;                // ���տ������ҵ���������ͼ��

IMAGE img_pea;                                  // �㶹ͼƬ

Atlas atlas_pea_break;                          // �㶹���鶯��ͼ��
Atlas atlas_sun;                                // �չ⶯��ͼ��
Atlas atlas_sun_explode;                        // �չⱬը����ͼ��
Atlas atlas_sun_ex;                             // �����չ⶯��ͼ��
Atlas atlas_sun_ex_explode;                     // �����չⱬը����ͼ��
Atlas atlas_sun_text;                           // ���ա� �ı�����ͼ��

Atlas atlas_run_effect;                         // ������Ч����ͼ��
Atlas atlas_jump_effect;                        // ��Ծ��Ч����ͼ��
Atlas atlas_land_effect;                        // �����Ч����ͼ��

IMAGE img_1P_winner;                            // 1P ��ʤ�ı�ͼƬ
IMAGE img_2P_winner;                            // 2P ��ʤ�ı�ͼƬ
IMAGE img_winner_bar;                           // ��ʤ��ұ����ı�ͼƬ

IMAGE img_avatar_peashooter;                    // ������ͷ��ͼƬ
IMAGE img_avatar_sunflower;                     // ���տ�ͷ��ͼƬ