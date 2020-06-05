#pragma once

#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <thread>
#include <mutex>
#include <chrono>
#include "Physics.h"
#include "BodyPair.h"
#include "../CTimer/CTimer.h"

namespace PEngine
{
    // Описание:
// класс, описывающий физический движок
    class PhysicsEngine
    {
    public:
        typedef std::set<Rigidbody*>::const_iterator const_iterator;

        PhysicsEngine();
        ~PhysicsEngine();

        // Описание:
        // метод запускает движок
        void Start();

        // Описание:
        // метод останавливает движок
        void Stop();

        // даем возможность просмотреть твердые тела, добавленные в движок
        // (позволяем воспользоваться константным итератором множества)
        const_iterator begin();
        const_iterator end();

        // Описание:
        // метод удаляет тело из движка
        void Remove(Rigidbody& rb);

        // Описание:
        // метод добавляет тело в движок
        void Add(Rigidbody& rb);

        // Описание:
        // метод удаляет все тела из движка
        void Clear();

        // Описание:
        // метод проверяет наличие тела в движке
        bool Contain(Rigidbody& rb);

    private:
        typedef Polygon* (*pfunc)(const Rigidbody&, const Rigidbody&);

        bool _isWork;
        std::set<Rigidbody*> _body;
        std::thread* _physicsThread;
        std::mutex _bodyMutex;

        // Описание:
        // словарь методов разрешения коллизий (первый ключ - имя формы первого тела, второй - второго)
        std::map<std::string, std::map<std::string, pfunc>> _interFunc =
                {
                        {"ConvexPolygon",
                                {
                                        {"ConvexPolygon", ConvPolyConvPoly},
                                        {"Circle", ConvPolyCircle},
                                }
                        },
                        {"Circle",
                                {
                                        {"ConvexPolygon", CircleConvPoly},
                                        {"Circle", CircleCircle},
                                }
                        },
                };

        void Work();

        // Описание:
        // широкая фаза
        std::set<BodyPair> WidePhase();

        // Описание:
        // метод проверяет возможность столкновения двух тел
        bool CanCollided(Rigidbody& rb1, Rigidbody& rb2);

        // Описание:
        // узкая фаза
        void NarrowPhase(std::set<BodyPair> potentials);

        static Polygon* ConvPolyConvPoly(const Rigidbody& rb1, const Rigidbody& rb2);
        static Polygon* ConvPolyCircle(const Rigidbody& rb1, const Rigidbody& rb2);
        static Polygon* CircleCircle(const Rigidbody& rb1, const Rigidbody& rb2);
        static Polygon* CircleConvPoly(const Rigidbody& rb1, const Rigidbody& rb2);
    };
}