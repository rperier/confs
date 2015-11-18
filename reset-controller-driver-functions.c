#define MESON_HHI_GCLK_OFFSET 0x1050

int meson_reset_assert(struct reset_controller_dev *rcdev,
                              unsigned long id)
{
    int bank = id / BITS_PER_LONG;
    int bit = id % BITS_PER_LONG;
    struct meson_reset_data *priv = container_of(rcdev,
                                        struct meson_reset_data, rcdev);
    u32 reg;

    reg = readl(priv->reset_base + MESON_HHI_GCLK_OFFSET + bank);
    reg |= BIT(bit);
    writel(reg, priv->reset_base + MESON_HHI_GCLK_OFFSET + bank);
    return 0;
}

static int meson_reset_deassert(struct reset_controller_dev *rcdev,
                                unsigned long id)
{
    int bank = id / BITS_PER_LONG;
    int bit = id % BITS_PER_LONG;
    struct meson_reset_data *priv = container_of(rcdev,
                                        struct meson_reset_data, rcdev);
    u32 reg;

    reg = readl(priv->reset_base + MESON_HHI_GCLK_OFFSET + bank);
    reg &= ~BIT(bit);
    writel(reg, priv->reset_base + MESON_HHI_GCLK_OFFSET + bank);
    return 0;
}
