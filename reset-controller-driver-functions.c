static int meson_reset_assert(struct reset_controller_dev *rcdev,
				  unsigned long id)
{
    u32 reg;
    struct meson_reset_data *priv = container_of(rcdev,
                                        struct meson_reset_data, rcdev);
    reg = readl(priv->reset_base);
    reg |= BIT(id + 24);
    writel(reg, priv->reset_base);
    return 0;
}

static int meson_reset_deassert(struct reset_controller_dev *rcdev,
				    unsigned long id)
{
    u32 reg;
    struct meson_reset_data *priv = container_of(rcdev,
                                        struct meson_reset_data, rcdev);
    reg = readl(priv->reset_base);
    reg &= ~BIT(id + 24);
    writel(reg, priv->reset_base);
    return 0;
}
