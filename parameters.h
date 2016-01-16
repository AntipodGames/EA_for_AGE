#ifndef PARAMETERS_H
#define PARAMETERS_H

namespace ea4age {

    struct parameters{

        static const int genome_size = 19;

        static const float distance_max = 640.+480.;
        static const float distance_min = 1.;

        static const float number_max = 100.;
        static const float number_min = 1.;

        static const float velocity_max = 100.*3.14;
        static const float velocity_min = 0.;

        static const float frequence_max = 500.;
        static const float frequence_min = 16.;

        static const float velocity_importance = 1.;
        static const float directions_importance = 1.;
        static const float shoot_importance = 1.;
    };

}

#endif // PARAMETERS_H
