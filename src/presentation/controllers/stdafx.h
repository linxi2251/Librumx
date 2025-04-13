// #pragma once
#ifndef STDAFX_H
#define STDAFX_H
#include <QQmlEngine>
#define Q_PROPERTY_AUTO_P(TYPE, M)                                                                 \
    Q_PROPERTY(TYPE M MEMBER _##M NOTIFY M##Changed)                                               \
public:                                                                                            \
    Q_SIGNAL void M##Changed();                                                                    \
    void M(TYPE in_##M) {                                                                          \
        m_##M = in_##M;                                                                             \
        Q_EMIT M##Changed();                                                                       \
    }                                                                                              \
    TYPE M() {                                                                                     \
        return m_##M;                                                                               \
    }                                                                                              \
                                                                                                   \
private:                                                                                           \
    TYPE m_##M;

#define Q_PROPERTY_AUTO(TYPE, M)                                                                   \
    Q_PROPERTY(TYPE M MEMBER m_##M NOTIFY M##Changed)                                               \
public:                                                                                            \
    Q_SIGNAL void M##Changed();                                                                    \
    void M(const TYPE &in_##M) {                                                                   \
        m_##M = in_##M;                                                                             \
        Q_EMIT M##Changed();                                                                       \
    }                                                                                              \
    TYPE M() {                                                                                     \
        return m_##M;                                                                               \
    }                                                                                              \
                                                                                                   \
private:                                                                                           \
    TYPE m_##M;


#define Q_PROPERTY_READONLY_AUTO(TYPE, M)                                                          \
    Q_PROPERTY(TYPE M READ M NOTIFY M##Changed FINAL)                                              \
public:                                                                                            \
    Q_SIGNAL void M##Changed();                                                                    \
    void M(const TYPE &in_##M) {                                                                   \
        m_##M = in_##M;                                                                             \
        Q_EMIT M##Changed();                                                                       \
    }                                                                                              \
    TYPE M() {                                                                                     \
        return m_##M;                                                                               \
    }                                                                                              \
                                                                                                   \
private:                                                                                           \
    TYPE m_##M;

#define DECLARE_FOREIGN_SINGLETON(TypeName)                                         \
    QML_ELEMENT                                                                     \
    QML_SINGLETON                                                                  \
    QML_FOREIGN(TypeName)                                                  \
    public:                                                                            \
    /* 静态单例指针，外部必须确保其初始化 */                                        \
    inline static TypeName* s_instance = nullptr;                                  \
                                                                                   \
    /* 单例创建方法 */                                                             \
    static TypeName* create(QQmlEngine* qmlEngine, QJSEngine* jsEngine) {          \
        Q_ASSERT(s_instance);           /* 确保实例已经初始化 */                       \
        Q_ASSERT(jsEngine->thread() == s_instance->thread()); /* 检查线程一致性 */ \
                                                                                   \
        if (s_engine) {                                                            \
            Q_ASSERT(jsEngine == s_engine);    /* 确保只有一个引擎访问单例 */          \
    } else {                                                                   \
            s_engine = jsEngine;                                                   \
    }                                                                          \
                                                                                   \
        /* 设置所有权为 C++，避免 QML 删除该对象 */                                 \
        QJSEngine::setObjectOwnership(s_instance, QJSEngine::CppOwnership);        \
        return s_instance;                                                        \
}                                                                              \
                                                                                   \
    private:                                                                           \
    /* 跟踪访问该单例的 QML 引擎 */                                                \
    inline static QJSEngine* s_engine = nullptr;

#endif
