
#include <jni.h>
/*
 * Class:     lib_io_lib_Deflib_io
 * Method:    calMmOne
 * Signature: (DDD)[D
 */
JNIEXPORT jdoubleArray JNICALL Java_lib_1io_lib_Deflib_1io_calMmOne
  (JNIEnv * env, jobject obj, jdouble n, jdouble labda, jdouble miu){

    double lambda = labda; // Tasa de llegada de clientes al sistema (clientes por unidad de tiempo)
    double mu = miu; // Tasa de servicio del servidor (clientes atendidos por unidad de tiempo)

    // Cálculo de métricas
    double utilization = lambda / mu;
    double avgNumCustomers = lambda / (mu - lambda);
    double rho = utilization;
    double avgNumCustomersQueue = (rho * rho) / (1 - rho);
    double avgTimeInSystem = 1 / (mu - lambda);
    double avgTimeInQueue = rho / (mu - lambda);

    // Calcular potencia manualmente en lugar de usar pow
    double rho_n = 1.0;
    for (int i = 0; i < n; i++) {
        rho_n *= rho;
    }

    // Guardar resultados en un arreglo
    double resultado[7];
    resultado[0] = avgNumCustomers;
    resultado[1] = avgTimeInSystem;
    resultado[2] = avgNumCustomersQueue;
    resultado[3] = avgTimeInQueue;
    resultado[4] = utilization;
    resultado[5] = 1 - utilization;
    resultado[6] = resultado[5] * rho_n;

    // Crear un jdoubleArray para devolver los resultados a Java
    jdoubleArray result = (*env)->NewDoubleArray(env, 7);
    if (result == NULL) {
        return NULL; // Error de asignación de memoria
    }

    // Copiar los resultados al jdoubleArray
    (*env)->SetDoubleArrayRegion(env, result, 0, 7, resultado);

    // Devolver el arreglo
    return result;

}
