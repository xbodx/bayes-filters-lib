#ifndef GAUSSIANLIKELIHOOD_H
#define GAUSSIANLIKELIHOOD_H

#include <BayesFilters/LikelihoodModel.h>

namespace bfl {
    class GaussianLikelihood;
}


class bfl::GaussianLikelihood : public LikelihoodModel
{
public:
    GaussianLikelihood() noexcept;

    GaussianLikelihood(const double scale_factor) noexcept;

    virtual ~GaussianLikelihood() noexcept { };

protected:
    std::pair<bool, Eigen::VectorXf> likelihood(const Process& process, const MeasurementModel& measurement_model, const Eigen::Ref<const Eigen::MatrixXf>& pred_states) override;

    double scale_factor_;
};

#endif /* GAUSSIANLIKELIHOOD_H */
