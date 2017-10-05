#ifndef ABSTRACTVISUALCORRECTION_H
#define ABSTRACTVISUALCORRECTION_H

#include "VisualObservationModel.h"

#include <Eigen/Dense>
#include <opencv2/core/core.hpp>

namespace bfl {
    class AbstractVisualCorrection;
}


class bfl::AbstractVisualCorrection
{
public:
    virtual ~AbstractVisualCorrection() noexcept { };

    virtual void correct(Eigen::Ref<Eigen::MatrixXf> states, Eigen::Ref<Eigen::MatrixXf> weights, cv::InputArray measurements) = 0;

    virtual void innovation(const Eigen::Ref<const Eigen::MatrixXf>& states, cv::InputArray measurements, Eigen::Ref<Eigen::MatrixXf> innovations) = 0;

    virtual void likelihood(const Eigen::Ref<const Eigen::MatrixXf>& innovations, Eigen::Ref<Eigen::MatrixXf> weights) = 0;

    virtual bool setObservationModelProperty(const std::string& property) = 0;

    virtual void observe(const Eigen::Ref<const Eigen::MatrixXf>& states, cv::OutputArray observations) = 0;
};

#endif /* ABSTRACTVISUALCORRECTION_H */
