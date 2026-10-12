# Tailscale

Tailscale is a mesh VPN that lets your devices communicate securely over the internet without configuring port forwarding or hosting your own VPN infrastructure.

We'll use it to access our server and its services remotely. Tailscale manages device authentication, networking, and encrypted connections using WireGuard.

## 1. Create an Account

Visit [Tailscale](https://tailscale.com/) and sign up using one of the supported identity providers, such as GitHub, Google, Microsoft, or Apple.

Once you've signed in, you'll have access to the [Admin Console](https://login.tailscale.com/admin), where you can manage your devices and network.

Your private Tailscale network is called a **tailnet**.

## 2. Install Tailscale

Navigate to **Admin Console → Machines → Add device** and select your operating system.

For Linux, the simplest installation method is:

```bash
curl -fsSL https://tailscale.com/install.sh | sh
```

Alternatively, follow the [official installation instructions](https://tailscale.com/docs/install/linux) for your distribution.

After installation, connect your machine:

```bash
sudo tailscale up
```

Tailscale will provide an authentication URL. Open it in any browser, sign in, and authorize the device.

This also works for headless servers. You don't need a browser installed on the server itself.

Verify your connection:

```bash
tailscale status
tailscale ip -4
```

The second command prints your machine's Tailscale IPv4 address.

### Adding Other Devices

Repeat this process for any additional computers.

For Android or iOS, install the Tailscale app, sign in with the same account, and enable the VPN connection.

You should now see your devices under **Admin Console → Machines**.

## 3. Connect to Your Server

With at least two devices connected, you can communicate between them over your tailnet.

Every device receives a private Tailscale IP address, usually beginning with `100.`.

For example, if your server hosts Jellyfin on port `8096`, you can open:

```text
http://100.x.x.x:8096
```

Replace the IP address with your server's Tailscale address that's shown in the dashboard.

You can also use Tailscale for SSH:

```bash
ssh username@100.x.x.x
```

Your devices must be connected to the tailnet, and the destination service must be running and reachable. Local firewalls and Tailscale access policies can still restrict connections.

## 4. Configure MagicDNS

Remembering IP addresses gets old pretty quickly.

**MagicDNS** lets you access devices using their hostnames instead.

Navigate to **Admin Console → DNS → MagicDNS** and ensure it's enabled. It's normally enabled by default on newer tailnets.

Now, instead of:

```text
http://100.x.x.x:8096
```

You can use:

```text
http://<hostname>:8096
```

You can also use the fully qualified Tailscale hostname:

```text
http://<hostname>.<tailnet-name>.ts.net:8096
```

Find your assigned tailnet name under **Admin Console → DNS**.

You can rename devices under **Admin Console → Machines → Select device → Edit machine name**.

## 5. Configure Named Services (Optional)

By default, you can access applications using your machine's hostname and port, such as `http://<hostname>:8080`.

Tailscale Services lets you assign applications their own addresses, making them easier to access without remembering port numbers.

For example, instead of `http://<hostname>:8080`, you could use `https://<service>.<tailnet-name>.ts.net`. 

### Create a Service

1. Navigate to **Admin Console → Services**.
2. Select **Advertise → Define a Service**.
3. Enter a name, such as `jellyfin`.
4. Add an endpoint using `tcp:443`.
5. Select **Add service**.

### Configure the Host Tag

Tailscale Services requires the hosting machine to have a tag.

1. Navigate to **Admin Console → Access controls → Definitions → Tags**.
2. Create a tag, such as `server`, and assign an owner.
3. Navigate to **Machines**, select your server, and assign the new tag.

Your machine can now act as a Tailscale Service host. When you advertise a service, you may need to approve it under **Admin Console → Services**.

### Configure the Host

On the machine running your application, execute something similar to:

```bash
sudo tailscale serve --service=svc:<service> --https=443 127.0.0.1:8080
```

Replace `<service>` with your service name and `8080` with the port your application uses.

This command configures an HTTPS endpoint that forwards requests to your local application. Tailscale automatically handles TLS certificates and runs the service in the background.

### Approve the Service

If approval is required, return to **Admin Console → Services** and approve the advertised service host. Ensure the machine is authorized to host the service under your tailnet's access policies.

Once approved, you can access your application at:

```text
https://<service>.<tailnet-name>.ts.net
```

You can verify your configuration using:

```bash
tailscale serve status
```

Repeat these steps for additional applications, assigning each its own service name.

**Note:** Named Services are only accessible to authorized devices on your tailnet. They are not exposed to the public internet.

## 6. Troubleshooting

If you can't connect to a device, start with:

```bash
tailscale status
tailscale ping <hostname>
```

If the device responds but its web application doesn't, check that the application is running and listening on the expected port.

On Linux, you can inspect listening ports with:

```bash
sudo ss -tulnp
```

Also check your system firewall. On openSUSE, for example:

```bash
sudo firewall-cmd --get-active-zones
```

Remember that Tailscale provides connectivity between machines; it doesn't automatically start services, open application ports in your host firewall, or override application-level authentication.

For more information, visit the [official Tailscale documentation](https://tailscale.com/docs).

## 7. Conclusion

Now with all of this set up, you can do a lot of cool things with your devices remotely. 

You can leave your desktop running at home and SSH into it from anywhere (ssh ranch@desktop), transfer files, push commits to GitHub, or work remotely as though you were sitting in front of it. You can access files, use jellyfin or romm, or whatever you want!

If after reading all of this you're still confused, don't hesitate to ask ChatGPT for help. 

## Appendix

| Generic Name | Example Name |
| --- | --- |
| `<username>@<hostname>` | ranch@kitty |
| `http://<hostname>.<tailnet-name>.ts.net:8096` | http://kitty.generated-name.ts.net:8096 |
| `https://<service>.<tailnet-name>.ts.net` | https://jellyfin.generated-name.ts.net | 


