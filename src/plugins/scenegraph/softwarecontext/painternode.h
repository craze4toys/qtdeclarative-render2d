/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Quick 2D Renderer module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef PAINTERNODE_H
#define PAINTERNODE_H

#include <private/qsgadaptationlayer_p.h>
#include <QtQuick/qquickpainteditem.h>

#include <QtGui/QPixmap>

class PainterNode : public QSGPainterNode
{
public:
    PainterNode(QQuickPaintedItem *item);
    ~PainterNode();

    void setPreferredRenderTarget(QQuickPaintedItem::RenderTarget target) override;

    void setSize(const QSize &size) override;
    QSize size() const { return m_size; }

    void setDirty(const QRect &dirtyRect = QRect()) override;

    void setOpaquePainting(bool opaque) override;
    bool opaquePainting() const { return m_opaquePainting; }

    void setLinearFiltering(bool linearFiltering) override;
    bool linearFiltering() const { return m_linear_filtering; }

    void setMipmapping(bool mipmapping) override;
    bool mipmapping() const { return m_mipmapping; }

    void setSmoothPainting(bool s) override;
    bool smoothPainting() const { return m_smoothPainting; }

    void setFillColor(const QColor &c) override;
    QColor fillColor() const { return m_fillColor; }

    void setContentsScale(qreal s) override;
    qreal contentsScale() const { return m_contentsScale; }

    void setFastFBOResizing(bool dynamic) override;
    bool fastFBOResizing() const { return m_fastFBOResizing; }

    QImage toImage() const override;
    void update() override;
    QSGTexture *texture() const override { return m_texture; }

    void paint(QPainter *painter);

    void paint();

    void setTextureSize(const QSize &size) override;
    QSize textureSize() const { return m_textureSize; }

private:

    QQuickPaintedItem::RenderTarget m_preferredRenderTarget;
    QQuickPaintedItem::RenderTarget m_actualRenderTarget;

    QQuickPaintedItem *m_item;

    QPixmap m_pixmap;
    QSGTexture *m_texture;

    QSize m_size;
    bool m_dirtyContents;
    QRect m_dirtyRect;
    bool m_opaquePainting;
    bool m_linear_filtering;
    bool m_mipmapping;
    bool m_smoothPainting;
    bool m_extensionsChecked;
    bool m_multisamplingSupported;
    bool m_fastFBOResizing;
    QColor m_fillColor;
    qreal m_contentsScale;
    QSize m_textureSize;

    bool m_dirtyGeometry;
};

#endif // PAINTERNODE_H
