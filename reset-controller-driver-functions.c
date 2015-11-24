static struct reset_control_ops meson_reset_ops = {
    .assert   = meson_reset_assert,
    .deassert = meson_reset_deassert,
};
int meson_reset_assert(struct reset_controller_dev *rcdev,
                       unsigned long id)
{
    /* Select the right bank and compute your offset */
[...]
    u32 reg = readl(priv->reset_base + offset);
    reg |= BIT(bit);
    writel(reg, priv->reset_base + offset);
    return 0;
}
static int meson_reset_deassert(struct reset_controller_dev *rcdev, unsigned long id)
{
[...]
    u32 reg = readl(priv->reset_base + offset);
    reg &= ~BIT(bit);
    writel(reg, priv->reset_base + offset);
    return 0;
}
