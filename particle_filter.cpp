#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>

using namespace std;

float randi()
{
    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    return r;
}

float process(float x, float x_N, int t)
{
    //out<<0.5*x + 25.0*x/(1 + pow(x,2.0)) + 8.0*cos(1.2*(t-1)) + sqrt(x_N)*randi()<<'\n';
    return 0.5*x + 25.0*x/(1 + pow(x,2.0)) + 8.0*cos(1.2*(t-1)) + sqrt(x_N)*randi();
}

float measurement(float x, float x_R)
{
    //cout<<pow(x,2.0)/20.0 + sqrt(x_R)*randi()<<'\n';
    return pow(x,2.0)/20.0 + sqrt(x_R)*randi();
}

vector<float> resample(vector<float> &X, vector<float> &w)
{
    vector<float> ans(w.size(),0);
    for (int i =1;i<w.size();i++)//cumsum
    {
        w[i] += w[i-1];
    }
    
    int x = 0;
    int count = 0;
    
    while (count < w.size())
    {
        x = randi();
        for (int i =0;i<w.size();i++)
        {
            if (w[i] >= x)
            {
                //cout<<X[i]<<'\n';
                ans[i] = X[i];
                break;
            }
        }
        count++;
    }
    
    return ans;
}

float probability_weight(float &z, float &z_partcl, float &x_R)
{
    return (1.0/sqrt(2.0*M_PI*x_R)) * exp(-pow((z-z_partcl),2.0)/(2.0 * x_R));
}

vector<float> particle_filter(int &N, int &T, float &z, float &x, float &x_N, float &x_R)
{
    vector<float> particles = {};
    vector<float> z_particles = {};
    vector<float> weights = {};
    vector<float> x_traj = {};
    vector<float> est_x_traj = {};
    
    float weight_sum = 0;
    
    //cout<<x<<'\n';
    for (int i = 0;i<N;i++)
    {
        //cout<<randi()*sqrt(x_N)<<'\n';
        particles.push_back(x + randi()*sqrt(x_N)); //Define initial set of particles
        //cout<<particles[i]<<'\n';
    }
    
    for (int i =0;i<T;i++)
    {
        x = process(x,x_N,i);
        z = measurement(x,x_R);
        z_particles = {};
        weights = {};
        for (int j =0;j<N;j++)
        {
            particles[j] = process(particles[j],x_N,i);
            z_particles.push_back(measurement(particles[j],0));
            weights.push_back(probability_weight(z,z_particles[j],x_R));
            
            //cout<<particles[j]<<'\n';
        }
        
        weight_sum = accumulate(weights.begin(),weights.end(),0.0)/weights.size();
        for (int j =0;j<N;j++)
        {
            weights[j] /= weight_sum;
        }
        
        
        particles = resample(particles,weights);
        
        x_traj.push_back(x);
        est_x_traj.push_back(accumulate(particles.begin(),particles.end(),0.0)/particles.size());

        cout<<x<<" "<<100*accumulate(particles.begin(),particles.end(),0.0)/particles.size()<<'\n';
        
    }
    
    return est_x_traj;
    
}

int main() {
    int N = 100;
    int T = 750;
    
    float x = 0.1; //true state
    float x_N = 1.0;
    float x_R = 1.0;
    float z = x + randi()*sqrt(x_R); //true obs
    
    //cout<<process(x, x_N, 1)<<'\n';
    //cout<<measurement(x, x_R)<<'\n';
    
    particle_filter(N,T,z,x,x_N,x_R);
	return 0;
}
