#include "Scene.h"


Scene::Scene(std::string _name, Util::Size _res, Palette::Color _colorA, Palette::Color _colorB)
{
    name = _name;
    set_background(_res, _colorA, _colorB);
}

void Scene::set_background(Util::Size _res, Palette::Color _colorA, Palette::Color _colorB)
{
    sf::VertexArray bg(sf::Quads, 4);
    bg[0].position = sf::Vector2f(0.f, 0.f);
    bg[1].position = sf::Vector2f((float)_res.width, 0.f);
    bg[2].position = sf::Vector2f((float)_res.width, (float)_res.height);
    bg[3].position = sf::Vector2f(0.f, (float)_res.height);

    _colorA.set_to(bg[0]);
    _colorA.set_to(bg[1]);

    _colorB.set_to(bg[2]);
    _colorB.set_to(bg[3]);

    sf::Transform t;
    background = { bg, t};
    Canvas::Render_item r = { &background.shape, &background.transform, false };
    add_to_layer(r, VIEW);
}

void Scene::add_listener(std::vector<Component::Input_listener>& _actions)
{
    for (auto& listener : _actions)
    {
        listeners.push_back(&listener);
    }
}

void Scene::add_listener(Component::Input_listener& _action)
{
    listeners.push_back((Component::Listener*) &_action);
}

void Scene::add_listener(std::vector<Component::Raw_listener>& _actions)
{
    for (auto& listener : _actions)
    {
        listeners.push_back((Component::Listener*) &listener);
    }
}

void Scene::add_listener(Component::Raw_listener& _action)
{
    listeners.push_back((Component::Listener*) &_action);
}

void Scene::add_to_layer(Canvas::Render_item _item, Layers _layer)
{
    switch (_layer)
    {
    case Scene::VIEW:
        view.push_back(_item);
        break;
    case Scene::UI:
        ui.push_back(_item);
        break;
    case Scene::DEBUG:
        debug.push_back(_item);
        break;
    default:
        break;
    }
}
