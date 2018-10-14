---
course: Virtualisierung und Cloud computing 
professor: Lukas, Uwe
semester: Winter 2017
---

- https://kubernetes.io/docs/setup/pick-right-solution/#local-machine-solutions
- https://kubernetes.io/docs/setup/minikube/
- https://kubernetes.io/docs/tasks/tools/install-kubectl/#before-you-begin
- https://github.com/kubernetes/minikube/blob/v0.30.0/README.md

# Install kvm plugin: 
    - Check dependencies: https://github.com/kubernetes/minikube/blob/master/docs/drivers.md#kvm-driver
    - Install plugin: https://github.com/dhiltgen/docker-machine-kvm/releases


# Tutorial 
- https://linuxhint.com/minikube_tutorial_made_easy/

- start minikube: `minikube start` or `minikube start --vm-driver=kvm`(in case of linux)
- status: `minikube status`

```sh
minikube: Running
cluster: Running
kubectl: Correctly Configured: pointing to minikube-vm at 192.168.42.12
```

- get services `kubectl get services`

```sh
NAME         TYPE        CLUSTER-IP   EXTERNAL-IP   PORT(S)   AGE
kubernetes   ClusterIP   10.96.0.1    <none>        443/TCP   2d
```

- get pods `kubectl get pods`

```sh
No resources found
```

- create pods

```sh
$ kubectl run mynginxapp --image=nginx:latest --port=80
kubectl run --generator=deployment/apps.v1beta1 is DEPRECATED and will be removed in a future version. Use kubectl create instead.
deployment.apps/mynginxapp created


$ kubectl get pods
NAME                          READY   STATUS              RESTARTS   AGE
mynginxapp-6d64f76d8f-q96s5   0/1     ContainerCreating   0          9s

# Wait until is ready
$ kubectl get pods
NAME                          READY   STATUS    RESTARTS   AGE
mynginxapp-6d64f76d8f-q96s5   1/1     Running   0          53s
```

- expose the service related to the app 

```sh
$ kubectl expose deployment mynginxapp --type=NodePort
service/mynginxapp exposed
```

- check exposed services

```sh
$ kubectl get services
NAME         TYPE        CLUSTER-IP       EXTERNAL-IP   PORT(S)        AGE
kubernetes   ClusterIP   10.96.0.1        <none>        443/TCP        2d
mynginxapp   NodePort    10.109.177.114   <none>        80:30243/TCP   36s
```

- Where is running our web server application

```sh
$ minikube service mynginxapp --url
http://192.168.42.12:30243
```

- We can even curl it

```sh
curl $(minikube service mynginxapp --url)
<!DOCTYPE html>
<html>
<head>
<title>Welcome to nginx!</title>
<style>
    body {
        width: 35em;
        margin: 0 auto;
        font-family: Tahoma, Verdana, Arial, sans-serif;
    }
</style>
</head>
<body>
<h1>Welcome to nginx!</h1>
<p>If you see this page, the nginx web server is successfully installed and
working. Further configuration is required.</p>

<p>For online documentation and support please refer to
<a href="http://nginx.org/">nginx.org</a>.<br/>
Commercial support is available at
<a href="http://nginx.com/">nginx.com</a>.</p>

<p><em>Thank you for using nginx.</em></p>
</body>
</html>
```

- Delete the service and deployment

```sh
$ kubectl delete service mynginxapp
service "mynginxapp" deleted
$ kubectl delete deployment mynginxapp
deployment "mynginxapp" deleted
```
