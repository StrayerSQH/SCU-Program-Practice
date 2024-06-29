#include "WindowsShow.h"
#include <iostream>

void WindowsShow::ShowWindow()
{
    // ��ȡ����ֱ��ʲ�����һ��ȫ������
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    // ����������Ϊ���Ĵ���ѧ��������ģ������
    window.create(desktop, "�Ĵ���ѧ��������ģ����", sf::Style::Fullscreen);
    // ����Ĭ�ϱ���ͼƬ������һ�����鲢��������Ϊ����ͼƬ
    sf::Texture DefaultBackgroundImg;
    if (!DefaultBackgroundImg.loadFromFile("1694597194197.jpg"))
    {
        std::cout << "�������Ĭ��ͼƬʧ�ܣ�����ͼƬ�Ƿ���ڣ�����" << std::endl;
        //sleep(3);
        //return -1;
    }
    //��ͼƬ����Ϊȫ��
    sf::Sprite background(DefaultBackgroundImg);
    background.setScale(
        window.getSize().x / background.getLocalBounds().width,
        window.getSize().y / background.getLocalBounds().height
    );

    // ��ȡ���ڴ�С
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2f windowSizeFloat(windowSize.x, windowSize.y);

    // ���Ʊ���
    window.draw(background);

}

sf::RenderWindow& WindowsShow::getWindow() {
    return window;
}